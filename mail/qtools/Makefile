# Created by: petef@FreeBSD.org
# $FreeBSD$

PORTNAME=	qtools
PORTVERSION=	0.56
PORTREVISION=	2
CATEGORIES=	mail
MASTER_SITES=	http://www.superscript.com/qtools/

MAINTAINER=	bdrewery@FreeBSD.org
COMMENT=	Tools to use in .qmail files

RUN_DEPENDS=	${EZMLM_DIR}/bin/ezmlm-weed:${PORTSDIR}/mail/ezmlm

USES=		qmail:vars
NO_STAGE=	yes

ALL_TARGET=	it
INSTALL_TARGET=	setup check

RESTRICTED=	Possibly restricted binary distribution of modified versions

EZMLM_DIR?=	${LOCALBASE}

post-patch:
	@${REINPLACE_CMD} -e 's|02755|0755|g' ${WRKSRC}/hier.c

do-configure:
	@${ECHO_CMD} "${CC} ${CFLAGS}" > ${WRKSRC}/conf-cc
	@${ECHO_CMD} "${CC} ${STRIP}" > ${WRKSRC}/conf-ld
	@${ECHO_CMD} "${PREFIX}" > ${WRKSRC}/conf-home
	@${ECHO_CMD} "${QMAIL_PREFIX}" > ${WRKSRC}/conf-qmail
	@${ECHO_CMD} "${EZMLM_DIR}/bin/ezmlm" > ${WRKSRC}/conf-ezmlm

.include <bsd.port.mk>
