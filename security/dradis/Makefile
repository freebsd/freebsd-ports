# New ports collection makefile for:    dradis
# Date created:				09 May 2010
# Whom:					Dax Labrador <semprix@bsdmail.org>
#
# $FreeBSD$
#

PORTNAME=	dradis
DISTVERSION=	2.5.2
CATEGORIES=	security
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/v${PORTVERSION}
DISTNAME=	${PORTNAME}-v${PORTVERSION}

MAINTAINER=	semprix@bsdmail.org
COMMENT=	Opensource framework to enable effective information gathering

RUN_DEPENDS=	rubygem-sqlite3>=1.2.4:${PORTSDIR}/databases/rubygem-sqlite3 \
		ruby18-wirble>=0.1.3:${PORTSDIR}/devel/ruby-wirble

LICENSE=	GPLv2

USE_RC_SUBR=	dradis
SUB_FILES=	pkg-message
SUB_LIST=	INSTDIR="${PREFIX}/${INSTDIR}" \
		RUBY_CMD=${RUBY_WITHOUT_SUFFIX}

INSTDIR?=	${PORTNAME}
WRKSRC=		${WRKDIR}/${PORTNAME}-2.5

NO_BUILD=	yes
USE_RUBY=	yes
USE_RAKE=	yes
DEPEND_RUBY_ICONV=	yes
RUBY_NO_BUILD_DEPENDS=	yes
USE_DOS2UNIX=	yes
DOS2UNIX_REGEX=	.*(css|rb|txt|js|RELEASE_NOTES)$$

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/bin/env ruby|${RUBY}|' ${WRKSRC}/server/script/server
	@${CHOWN} -R root:wheel ${WRKSRC}/server
	@${FIND} ${WRKSRC}/server -type f \( -name "*.bak" -o -name "*.orig" \) -delete

do-install:
	@${MKDIR} ${PREFIX}/${PORTNAME}
	@${CP} -Rp ${WRKSRC}/server ${PREFIX}/${PORTNAME}/

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
