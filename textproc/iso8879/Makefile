# New ports collection makefile for:	iso8879
# Date created:		June 19, 1997
# Whom:			jfieber
#
# $FreeBSD$
#

PORTNAME=	iso8879
PORTVERSION=	1986
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	kuriyama
DISTNAME=	isoENTS
EXTRACT_SUFX=	.zip

MAINTAINER=	kuriyama@FreeBSD.org

BUILD_DEPENDS=	unzip:${PORTSDIR}/archivers/unzip
RUN_DEPENDS=	${MKCATALOG}:${PORTSDIR}/textproc/mkcatalog

EXTRACT_ONLY=	# empty
NO_BUILD=	yes
NO_WRKSUBDIR=	yes
PLIST_SUB=	DTD_NAME=${PORTNAME} MKCATALOG=${MKCATALOG}

INSTDIR=	${PREFIX}/share/sgml/iso8879
MKCATALOG=	${PREFIX}/sbin/mkcatalog

pre-install:
	@[ -d ${INSTDIR} ] || ${MKDIR} ${INSTDIR}

do-install:
	@unzip -a -q -o ${DISTDIR}/${DISTFILES} -d ${INSTDIR}
	@${INSTALL_DATA} ${FILESDIR}/catalog ${INSTDIR}/catalog
	@${CHMOD} ${SHAREMODE} ${INSTDIR}/*
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${INSTDIR}

post-install:
	@${MKCATALOG} -q install ${PORTNAME}

.include <bsd.port.mk>
