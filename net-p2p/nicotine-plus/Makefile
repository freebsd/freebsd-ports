# New ports collection makefile for:	nicotine
# Date created:				19 Aug 2003
# Whom:					Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	plus
PORTVERSION=	1.2.7.1
CATEGORIES=	net-p2p
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PKGNAMEPREFIX}${PORTNAME}
PKGNAMEPREFIX=	nicotine-
DISTNAME=	${PKGNAMEPREFIX:S/-/+/}-${PORTVERSION}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	A fork of nicotine soulseek client

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/_bsddb.so:${PORTSDIR}/databases/py-bsddb

CONFLICTS=	nicotine-[0-9]*

USE_BZIP2=		yes
USE_GNOME=		pygtk2
USE_PYTHON=		yes
USE_PYDISTUTILS=	yes
USE_GETTEXT=		yes

DOCSDIR=	share/doc/${PKGNAMEPREFIX:S/-//}
DATADIR=	share/${PKGNAMEPREFIX:S/-//}
MAN1=		nicotine-import-winconfig.1 nicotine.1

OPTIONS=	GEOIP "Enable the GeoIP based country code blocker" off \
		PSYCO "Enable Psyco, the optimizing Python compiler" on \
		VORBIS "Enable OGG/Vorbis support" on

.include <bsd.port.pre.mk>

.if defined(WITH_GEOIP)
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/GeoIP.so:${PORTSDIR}/net/py-GeoIP
.endif
.if defined(WITH_PSYCO) && ${ARCH} == "i386"
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/psyco/_psyco.so:${PORTSDIR}/devel/py-psyco
.endif
.if defined(WITH_VORBIS)
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/ogg/vorbis.so:${PORTSDIR}/audio/py-vorbis
.endif

post-patch:
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -i "" -e 's|^doc_files.*|doc_files = ""|g' ${WRKSRC}/setup.py
.endif
	@${REINPLACE_CMD} -e "s|sys\.prefix|\"${PREFIX}\"|g" ${WRKSRC}/setup.py

.include <bsd.port.post.mk>
