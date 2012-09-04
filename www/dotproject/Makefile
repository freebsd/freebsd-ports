# $FreeBSD$

PORTNAME=	dotproject
PORTVERSION=	2.1.5
PORTREVISION=	2
CATEGORIES=	www devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/dotProject%20Version%20${PORTVERSION}

MAINTAINER=	garga@FreeBSD.org
COMMENT=	Open Source Project Management tool

WRKSRC=		${WRKDIR}/${PORTNAME}
NO_BUILD=	yes
USE_PHP=	gd mysql session zlib
WANT_PHP_WEB=	yes
USE_APACHE_RUN=	22+

SUB_FILES=	pkg-message

OPTIONS_DEFINE=	LDAP
OPTIONS_DEFAULT=LDAP

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MLDAP}
USE_PHP+=	ldap xml
.endif

do-install:
	${MKDIR} ${WWWDIR}
	${CP} -R ${WRKSRC}/* ${WWWDIR}
	${RM} ${WWWDIR}/locales/es
	${RM} ${WWWDIR}/locales/pt_br
	${MKDIR} ${WWWDIR}/files/temp
	${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
