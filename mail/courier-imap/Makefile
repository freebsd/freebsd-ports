# New ports collection makefile for: courierimap
# Date created:		19 Feb 2000
# Whom:			Neil Blakey-Milner
#
# $FreeBSD$
#

PORTNAME=	courier-imap
PORTVERSION=	1.0
CATEGORIES=	mail ipv6
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	courier

MAINTAINER=	nbm@FreeBSD.org

GNU_CONFIGURE=	YES
USE_GMAKE=	YES

.if !exists(/usr/include/openssl/idea.h)
CFLAGS+=	-DNO_IDEA
.endif

CONFIGURE_ARGS=	--without-authldap --with-authldaprc=filename \
		--without-authpam --without-authshadow \
		--without-authvchkpw --without-authcram \
		--with-userdb=${PREFIX}/etc/userdb \
		--datadir=${PREFIX}/share/courier-imap \
		--disable-root-check

MAN1=		maildirmake.1
MAN8=		authlib.8 makeuserdb.8 userdb.8 userdbpw.8 couriertcpd.8 \
		deliverquota.8 imapd.8 mkimapdcert.8

MLINKS=		authlib.8 authpwd.8 \
		authlib.8 authuserdb.8 \
		authlib.8 authshadow.8 \
		authlib.8 authpam.8 \
		authlib.8 authvchkpw.8 \
		authlib.8 authcram.8 \
		authlib.8 authldap.8 \
		authlib.8 authmysql.8 \
		authlib.8 authdaemon.8 \
		makeuserdb.8 pw2userdb.8 \
		makeuserdb.8 vchkpw2userdb.8

EXTRA_DOCS=	README INSTALL AUTHORS imap/ChangeLog

.include <bsd.port.pre.mk>

post-patch:
	@perl -i -pe 's@(\$$.sysconfdir./\$$\$$p)@\1.dist@' \
		${WRKSRC}/imap/Makefile.in

post-install:
	@${MKDIR} ${PREFIX}/share/doc/courier-imap
.for a in ${EXTRA_DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${a} ${PREFIX}/share/doc/courier-imap/
.endfor

.include <bsd.port.post.mk>
