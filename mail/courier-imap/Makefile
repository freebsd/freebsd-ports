# New ports collection makefile for: courierimap
# Date created:		19 Feb 2000
# Whom:			Neil Blakey-Milner
#
# $FreeBSD$
#

PORTNAME=	courier-imap
PORTVERSION=	1.3.5
PORTREVISION=	1
CATEGORIES=	mail ipv6
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	courier

MAINTAINER=	nbm@FreeBSD.org

GNU_CONFIGURE=	YES
USE_GMAKE=	YES


.if !defined(WITHOUT_OPENSSL)
USE_OPENSSL=	YES
PLIST_SUB=	OPENSSLFLAG=
.else
PLIST_SUB=	OPENSSLFLAG="@comment "
.endif

.if !exists(/usr/include/openssl/idea.h)
CFLAGS+=	-DNO_IDEA
.endif

CONFIGURE_ARGS=	--without-authldap --with-authldaprc=filename \
		--without-authpam --without-authshadow \
		--without-authvchkpw --without-authcram \
		--without-authmysql \
		--sysconfdir=${PREFIX}/etc/courier-imap \
		--with-userdb=${PREFIX}/etc/userdb \
		--datadir=${PREFIX}/share/courier-imap \
		--libexecdir=${PREFIX}/libexec/courier-imap \
		--enable-workarounds-for-imap-client-bugs \
		--disable-root-check

MAN1=		maildirmake.1
MAN8=		authlib.8 makeuserdb.8 userdb.8 userdbpw.8 couriertcpd.8 \
		deliverquota.8 imapd.8 mkimapdcert.8 mkpop3dcert.8

MLINKS=		authlib.8 authpwd.8 \
		authlib.8 authuserdb.8 \
		authlib.8 authshadow.8 \
		authlib.8 authpam.8 \
		authlib.8 authvchkpw.8 \
		authlib.8 authcram.8 \
		authlib.8 authldap.8 \
		authlib.8 authmysql.8 \
		authlib.8 authdaemon.8 \
		authlib.8 authdaemond.8 \
		makeuserdb.8 pw2userdb.8 \
		makeuserdb.8 vchkpw2userdb.8

EXTRA_DOCS=	README INSTALL AUTHORS imap/ChangeLog

.include <bsd.port.pre.mk>

post-patch:
	@perl -i.nbm -pe 'm#^sysconf_DATA = imapd.dist# && s@[ip][mo][ap][p3]d.cnf@@g;' \
		${WRKSRC}/Makefile.in

post-install:
	@${MKDIR} ${PREFIX}/share/doc/courier-imap
	@${INSTALL_DATA} ${WRKSRC}/imap/imapd.cnf ${PREFIX}/etc/courier-imap/imapd.cnf.dist
	@${INSTALL_DATA} ${WRKSRC}/imap/pop3d.cnf ${PREFIX}/etc/courier-imap/pop3d.cnf.dist
.for a in ${EXTRA_DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${a} ${PREFIX}/share/doc/courier-imap/
.endfor

.include <bsd.port.post.mk>
