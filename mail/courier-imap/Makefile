# New ports collection makefile for: courierimap
# Version required:	0.26
# Date created:		19 Feb 2000
# Whom:			Neil Blakey-Milner
#
# $FreeBSD$
#

DISTNAME=	courier-imap-0.26
CATEGORIES=	mail
MASTER_SITES=	http://www.inter7.com/courierimap/

MAINTAINER=	nbm@FreeBSD.org

GNU_CONFIGURE=	YES
USE_GMAKE=	YES

CONFIGURE_ARGS=	--without-authldap --with-authldaprc=filename \
		--without-authpam --without-authshadow \
		--without-authvchkpw --without-authcram

MAN8=		authlib.8 makeuserdb.8 userdb.8 userdbpw.8 couriertcpd.8 \
		deliverquota.8 imapd.8

MLINKS=		authlib.8 authpwd.8 authlib.8 authshadow.8 \
		authlib.8 authuserdb.8 authlib.8 authpam.8 \
		authlib.8 authvchkpw.8 authlib.8 authcram.8 \
		authlib.8 authldap.8 makeuserdb.8 pw2userdb.8 \
		makeuserdb.8 vchkpw2userdb.8

.include <bsd.port.mk>
