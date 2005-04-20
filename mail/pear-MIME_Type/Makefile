# Ports collection makefile for:  pear-MIME_Type
# Date created:			  18 April 2005
# Whom:				  Antonio Carlos Venancio Junior (<antonio@inf.ufsc.br>)
#
# $FreeBSD$
#

PORTNAME=	MIME_Type
PORTVERSION=	1.0.0
CATEGORIES=	mail www pear

MAINTAINER=	antonio@php.net
COMMENT=	PEAR class for dealing with MIME types

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear-PEAR
RUN_DEPENDS=	${BUILD_DEPENDS}

LATEST_LINK=	pear-${PORTNAME}
OPTIONS=	PEAR_SYSTEM_COMMAND "PEAR::System_Command support" off

USE_REINPLACE=	yes

CATEGORY=	MIME
FILES=		Type.php Type/Parameter.php
EXAMPLES=	example.php
_EXAMPLESDIR=	.

post-extract:
	@${MKDIR} ${WRKSRC}/Type
	@${MV} ${WRKSRC}/Parameter.php ${WRKSRC}/Type

.include <bsd.port.pre.mk>

.if defined(WITH_PEAR_SYSTEM_COMMAND)
RUN_DEPENDS+=	${PEARDIR}/System/Command.php:${PORTSDIR}/devel/pear-System_Command
.endif

.include "${PORTSDIR}/devel/pear-PEAR/Makefile.common"

post-patch:
.for file in ${FILES}
	@${REINPLACE_CMD} -e "s|@version@|${PORTVERSION}|" ${WRKSRC}/${file}
	@${REINPLACE_CMD} -e "s|@package@|${PORTNAME}|" ${WRKSRC}/${file}
.endfor
	@${REINPLACE_CMD} -e "s|@doc_dir@|${EXAMPLESDIR}|" ${WRKSRC}/${EXAMPLES}

.include <bsd.port.post.mk>
