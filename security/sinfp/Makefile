# New ports collection makefile for:	sinfp
# Date created:		26 May 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	sinfp
PORTREVISION=	${DBDATE}

MAINTAINER=	sbrabez@gmail.com
COMMENT=	Full operating system stack fingerprinting suite

BUILD_DEPENDS=	p5-Net-SinFP>=2.02:${PORTSDIR}/security/p5-Net-SinFP
RUN_DEPENDS:=	${BUILD_DEPENDS}

PLIST=		""
PLIST_FILES=	bin/${PORTNAME} \
		%%DATADIR%%/${PORTNAME}.db
PLIST_DIRS=	%%DATADIR%%
NO_BUILD=	yes
MASTERDIR=	${.CURDIR}/../p5-Net-SinFP
DBDATE=		20101224

post-patch:
	@${REINPLACE_CMD} -e 's!$$Bin/../db/!${DATADIR}/!' ${WRKSRC}/bin/${PORTNAME}.pl

do-install:
	@${INSTALL} -d ${DATADIR}/
	@${INSTALL_SCRIPT} ${WRKSRC}/bin/${PORTNAME}.pl ${PREFIX}/bin/${PORTNAME}
.ifdef DBDATE
	@${INSTALL_DATA} ${_DISTDIR}/${PORTNAME}-${DBDATE}.db ${DATADIR}/${PORTNAME}.db
.else
	@${INSTALL_DATA} ${WRKSRC}/bin/${PORTNAME}.db ${DATADIR}/
.endif

.include "${MASTERDIR}/Makefile"
