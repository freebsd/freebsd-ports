# New ports collection makefile for:    apache mod_auth_mysql
# Date created:		2000/05/19
# Whom:			jim@thehouselys.net
#
# $FreeBSD$

PORTNAME=	mod_auth_mysql
PORTVERSION=	2.20
PORTREVISION=	7
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	mod-auth-mysql

MAINTAINER=	jeh@FreeBSD.org
COMMENT=	Allows users to use MySQL databases for user authentication

BUILD_DEPENDS=	${APXS}:${PORTSDIR}/${APACHE_PORT}
RUN_DEPENDS=	${LOCALBASE}/sbin/${AP_TARGET}:${PORTSDIR}/${APACHE_PORT}

USE_MYSQL=	yes

WANT_APACHE=	13
AP_GENPLIST=	yes
PORTDOCS=	README USAGE
PLIST_FILES+=	libexec/apache/libauth_mysql.so

PKGMESSAGE=	${WRKSRC}/.install_notes

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-mysql=${PREFIX} \
		--with-apxs=${APXS}

.include "${.CURDIR}/../apache2/Makefile.modules.3rd"

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
