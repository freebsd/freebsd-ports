# Ports collection makefile for:	crashecho
# Date created:		15 November 2002
# Whom:			CyrilM <cyrilm@tower.pp.ru>
#
# $FreeBSD$
#

PORTNAME=	crashecho
PORTVERSION=	0.2.14
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.nluug.nl/pub/ibiblio/distributions/altlinux/${MASTER_SITE_SUBDIR} \
		ftp://distro.ibiblio.org/pub/linux/distributions/altlinux/${MASTER_SITE_SUBDIR} \
		ftp://ftp.chg.ru/.1/Linux/ALTLinux/${MASTER_SITE_SUBDIR}
MASTER_SITE_SUBDIR=	Sisyphus/files/SRPMS/
EXTRACT_SUFX=	.rpm
DISTFILES=	${PORTNAME}-${PORTVERSION}-alt1.src${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An FTN JAM and *.MSG tosser

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

EXTRACT_DEPENDS=rpm2cpio:${PORTSDIR}/archivers/rpm
LIB_DEPENDS=	jam.2:${PORTSDIR}/mail/jamlib

EXTRACT_CMD=	rpm2cpio
EXTRACT_BEFORE_ARGS=	# empty
EXTRACT_AFTER_ARGS=	| ${CPIO} -i

GNU_CONFIGURE=	yes

MAN1=	crashecho.1 \
	crashexport.1 \
	crashmaint.1 \
	crashstats.1 \
	crashwrite.1
MAN5=	crashecho.conf.5

post-extract:
	cd ${WRKDIR} && tar zxf ${PORTNAME}-${PORTVERSION}.tar.gz

post-install:
	${MKDIR} ${PREFIX}/etc/ftn
	${INSTALL_DATA} ${WRKSRC}/doc/crashecho.conf ${PREFIX}/etc/ftn/crashecho.conf.sample

.include <bsd.port.mk>
