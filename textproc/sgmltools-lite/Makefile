# New ports collection makefile for:	sgmltools
# Date created:				7 Apr 2000
# Whom:					Benno Rice <benno@netizen.com.au>
#
# $FreeBSD$
#

PORTNAME=	sgmltools-lite
PORTVERSION=	3.0.0
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	sgmltools-lite

MAINTAINER=	benno@netizen.com.au

BUILD_DEPENDS+=	python:${PORTSDIR}/lang/python \
		jade:${PORTSDIR}/textproc/jade \
		${LOCALBASE}/share/texmf:${PORTSDIR}/print/teTeX
RUN_DEPENDS+=	${LOCALBASE}/share/sgml/docbook:${PORTSDIR}/textproc/docbook \
		${LOCALBASE}/share/sgml/docbook/dsssl:${PORTSDIR}/textproc/dsssl-docbook-modular

MAN1=		sgmltools.1
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-etcsgml=${PREFIX}/etc/sgml

pre-configure:
	${RM} -f ${WRKSRC}/config.cache

pre-install:
	${MKDIR} ${PREFIX}/etc/sgml

post-install:
	${ECHO} "3.0.0" > ${LOCALBASE}/share/sgml/misc/sgmltools/VERSION

.include <bsd.port.mk>
