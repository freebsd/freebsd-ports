# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$

PORTNAME=	plus
PORTVERSION=	1.2.16
CATEGORIES=	net-p2p
MASTER_SITES=	SF/nicotine-${PORTNAME}/nicotine-${PORTNAME}/${PORTVERSION}
PKGNAMEPREFIX=	nicotine-
DISTNAME=	${PKGNAMEPREFIX:S/-/+/}-${PORTVERSION}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	A fork of nicotine soulseek client

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}bsddb>0:${PORTSDIR}/databases/py-bsddb

CONFLICTS=	nicotine-[0-9]*
BROKEN=		does not build

DEPRECATED=	Broken for more than 6 month
EXPIRATION_DATE=	2013-08-27

USE_BZIP2=		yes
USE_GNOME=		pygtk2
USE_PYTHON=		yes
USE_PYDISTUTILS=	yes
USES=		gettext
PYDISTUTILS_PKGNAME=	nicotine

DOCSDIR=	share/doc/${PKGNAMEPREFIX:S/-//}
DATADIR=	share/${PKGNAMEPREFIX:S/-//}
MAN1=		nicotine-import-winconfig.1 nicotine.1

OPTIONS_DEFINE=	GEOIP PSYCO MUTAGEN LIBSEXY MINIUPNPC DOCS
OPTIONS_DEFINE_i386=	PSYCO
OPTIONS_DEFAULT=	GEOIP PSYCO MUTAGEN LIBSEXY MINIUPNPC
GEOIP_DESC=	Enable the GeoIP based country code blocker
PSYCO_DESC=	Enable Psyco, the optimizing Python compiler
MUTAGEN_DESC=	Enable Mutagen for audio metadata support
LIBSEXY_DESC=	Enable libsexy support
MINIUPNPC_DESC=	Enable upnp support

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGEOIP}
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/GeoIP.so:${PORTSDIR}/net/py-GeoIP
.endif
.if ${PORT_OPTIONS:MPSYCO}
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/psyco/_psyco.so:${PORTSDIR}/devel/py-psyco
.endif
.if ${PORT_OPTIONS:MMUTAGEN}
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/mutagen/__init__.py:${PORTSDIR}/audio/py-mutagen
.endif
.if ${PORT_OPTIONS:MLIBSEXY}
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/gtk-2.0/sexy.so:${PORTSDIR}/x11-toolkits/py-sexy
.endif
.if ${PORT_OPTIONS:MMINIUPNPC}
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/miniupnpc.so:${PORTSDIR}/net/py-miniupnpc
.endif

post-extract:
	@${MV} ${WRKSRC}/${PKGNAMEPREFIX:S/-//}.py ${WRKSRC}/${PKGNAMEPREFIX:S/-//}

post-patch:
.if ! ${PORT_OPTIONS:MDOCS}
	@${REINPLACE_CMD} -i "" -e 's|^doc_files.*|doc_files = ""|g' ${WRKSRC}/setup.py
.endif
	@${REINPLACE_CMD} -e \
		"s|sys\.prefix|\"${PREFIX}\"|g" -e \
			"s|nicotine.py|nicotine|g" ${WRKSRC}/setup.py

.include <bsd.port.mk>
