# New ports collection makefile for:	nicotine
# Date created:				19 Aug 2003
# Whom:					Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	nicotine
PORTVERSION=	1.0.7
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://nicotine.thegraveyard.org/

MAINTAINER=	sw@gegenunendlich.de
COMMENT=	GTK2 SoulSeek filesharing client

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/gtk-2.0/gtk/__init__.py:${PORTSDIR}/x11-toolkits/py-gtk2 \
		${PYTHON_SITELIBDIR}/_bsddb.so:${PORTSDIR}/databases/py-bsddb

USE_BZIP2=		yes
USE_PYTHON=		yes
USE_PYDISTUTILS=	yes
USE_REINPLACE=		yes

.include <bsd.port.pre.mk>

.if exists(${PYTHON_SITELIBDIR}/GeoIP.so) || defined(WITH_GEOIP)
WITH_GEOIP=	yes
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/GeoIP.so:${PORTSDIR}/net/py-GeoIP
.endif

.if exists(${PYTHON_SITELIBDIR}/psyco/_psyco.so) || defined(WITH_PSYCO)
WITH_PSYCO=	yes
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/psyco/_psyco.so:${PORTSDIR}/devel/py-psyco
.endif

.if exists(${PYTHON_SITELIBDIR}/ogg/vorbis.so) || defined(WITH_VORBIS)
WITH_VORBIS=	yes
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/ogg/vorbis.so:${PORTSDIR}/audio/py-vorbis
.endif

.if !defined(WITH_VORBIS) || !defined(WITH_PSYCO) || !defined(WITH_GEOIP)
pre-everything::
	@${ECHO_MSG} ""
	@${ECHO_MSG} "You can define the following for additional features:"
	@${ECHO_MSG} ""
.if !defined(WITH_GEOIP)
	@${ECHO_MSG} "WITH_GEOIP  - enable the GeoIP based country code blocker"
.endif
.if !defined(WITH_PSYCO)
	@${ECHO_MSG} "WITH_PSYCO  - enable the psyco optimizing compiler"
.endif
.if !defined(WITH_VORBIS)
	@${ECHO_MSG} "WITH_VORBIS - enable OGG/Vorbis support"
.endif
	@${ECHO_MSG} ""
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
