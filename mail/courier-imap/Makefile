# New ports collection makefile for: courierimap
# Date created:		19 Feb 2000
# Whom:			Neil Blakey-Milner
#
# $FreeBSD$
#

PORTNAME=	courier-imap
PORTVERSION=	0.33
CATEGORIES=	mail ipv6
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	courier

MAINTAINER=	nbm@FreeBSD.org

GNU_CONFIGURE=	YES
USE_GMAKE=	YES

CONFIGURE_ARGS=	--without-authldap --with-authldaprc=filename \
		--without-authpam --without-authshadow \
		--without-authvchkpw --without-authcram

MAN1=		maildirmake.1
MAN8=		authlib.8 makeuserdb.8 userdb.8 userdbpw.8 couriertcpd.8 \
		deliverquota.8 imapd.8

MLINKS=		authlib.8 authpwd.8 \
		authlib.8 authuserdb.8 \
		makeuserdb.8 pw2userdb.8 \
		makeuserdb.8 vchkpw2userdb.8

.include <bsd.port.pre.mk>

post-patch:
	@perl -i -pe s'@^if test -w confmdtest1$$@if test -z 0@' \
		${WRKSRC}/configure
.if ${OSVERSION} >= 400016
	@perl -i -pe 's@^#include\s*<netinet6/in6.h>$$@@' \
		${WRKSRC}/rfc1035/configure \
		${WRKSRC}/rfc1035/rfc1035.h.in
.endif

.include <bsd.port.post.mk>
