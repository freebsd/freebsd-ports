# New ports collection makefile for:	iso8879
# Version required:	1986
# Date created:		June 19, 1997
# Whom:			jfieber
#
# $Id: Makefile,v 1.7 1998/09/29 17:28:34 jkh Exp $
#

DISTNAME=	isoENTS
PKGNAME=	iso8879-1986
CATEGORIES=	textproc
MASTER_SITES=	ftp://fallout.campusview.indiana.edu/pub/sgml/
EXTRACT_SUFX=	.zip

MAINTAINER=	jfieber@FreeBSD.ORG

BUILD_DEPENDS=	unzip:${PORTSDIR}/archivers/unzip

NO_MTREE=       yes
EXTRACT_ONLY=	# empty
NO_BUILD=       yes
NO_WRKSUBDIR=	yes

INSTDIR=	${PREFIX}/share/sgml/iso8879

pre-install:
	@[ -d ${INSTDIR} ] || ${MKDIR} ${INSTDIR}

do-install:
	@unzip -a -q -o ${DISTDIR}/${DISTFILES} -d ${INSTDIR}
	@${INSTALL_DATA} ${FILESDIR}/catalog ${INSTDIR}/catalog
	@chmod ${SHAREMODE} ${INSTDIR}/*
	@/usr/sbin/chown -R ${SHAREOWN}.${SHAREGRP} ${INSTDIR}

.include <bsd.port.mk>
