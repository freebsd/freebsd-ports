# New ports collection makefile for:	iso8879
# Version required:	1.0
# Date created:		June 19, 1997
# Whom:			jfieber
#
# $Id: Makefile,v 1.1.1.1 1997/06/22 21:01:27 jfieber Exp $
#

DISTNAME=	isoENTS
PKGNAME=	iso8879-1.0
CATEGORIES=	textproc
MASTER_SITES=	http://www.sil.org/sgml/
EXTRACT_SUFX=	.zip

MAINTAINER=	jfieber@FreeBSD.ORG

BUILD_DEPENDS=	unzip:${PORTSDIR}/archivers/unzip

NO_MTREE=       yes
NO_EXTRACT=     yes
NO_BUILD=       yes
NO_PATCH=	yes
NO_CONFIGURE=	yes
NO_WRKDIR=      yes

INSTDIR=	${PREFIX}/share/sgml/iso8879/

pre-install:
	@[ -d ${INSTDIR} ] || ${MKDIR} ${INSTDIR}

do-install:
	@unzip -a -q -o -d ${INSTDIR} ${DISTDIR}/${DISTFILES}
	@${INSTALL_DATA} ${FILESDIR}/catalog ${INSTDIR}/catalog
	@chmod ${SHAREMODE} ${INSTDIR}/*
	@/usr/sbin/chown -R ${SHAREOWN}.${SHAREGRP} ${INSTDIR}

.include <bsd.port.mk>
