# Created by: James Flemer <jflemer@acm.jhu.edu>
# $FreeBSD$

PORTNAME=	docsis
PORTVERSION=	0.9.5
PORTREVISION=	5
CATEGORIES=	net-mgmt
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	jflemer@alum.rpi.edu
COMMENT=	DOCSIS(tm) binary configuration file encoder/decoder

BUILD_DEPENDS=	gm4:${PORTSDIR}/devel/m4
LIB_DEPENDS=	netsnmp:${PORTSDIR}/net-mgmt/net-snmp

GNU_CONFIGURE=	yes
USE_OPENSSL=	yes
USES=		bison

PLIST_SUB=	MIBS=share/snmp/mibs

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
BROKEN=		Produces corrupt files on amd64
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|^htmldocdir =.*|htmldocdir = ${DOCSDIR}|' ${WRKSRC}/doc/Makefile.in
	@${REINPLACE_CMD} -e 's|^examplesdir =.*|examplesdir = ${EXAMPLESDIR}|' ${WRKSRC}/examples/Makefile.in

.include <bsd.port.post.mk>
