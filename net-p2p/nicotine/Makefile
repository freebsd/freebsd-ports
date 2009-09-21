# New ports collection makefile for:	nicotine
# Date created:				19 Aug 2003
# Whom:					Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	nicotine
PORTVERSION=	1.0.8
PORTREVISION=	3
CATEGORIES=	net-p2p
MASTER_SITES=	http://nicotine.thegraveyard.org/

MAINTAINER=	stefan@FreeBSD.org
COMMENT=	GTK2 SoulSeek filesharing client

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/gtk-2.0/gtk/__init__.py:${PORTSDIR}/x11-toolkits/py-gtk2 \
		${PYTHON_SITELIBDIR}/_bsddb.so:${PORTSDIR}/databases/py-bsddb

USE_BZIP2=		yes
USE_PYTHON=		yes
USE_PYDISTUTILS=	yes
USE_GETTEXT=		yes

DEPRECATED=		development stalled years ago, use net-p2p/nicotine-plus instead
EXPIRATION_DATE=	2009-10-31

OPTIONS=	GEOIP "Enable the GeoIP based country code blocker" off \
		PSYCO "Enable Psyco, the optimizing Python compiler" off \
		VORBIS "Enable OGG/Vorbis support" on

.include <bsd.port.pre.mk>

.if defined(WITH_GEOIP)
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/GeoIP.so:${PORTSDIR}/net/py-GeoIP
.endif
.if defined(WITH_PSYCO)
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/psyco/_psyco.so:${PORTSDIR}/devel/py-psyco
.endif
.if defined(WITH_VORBIS)
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/ogg/vorbis.so:${PORTSDIR}/audio/py-vorbis
.endif

post-patch:
	@${REINPLACE_CMD} -e "s|sys\.prefix|\"${PREFIX}\"|g" ${WRKSRC}/setup.py

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README.import-winconfig ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
