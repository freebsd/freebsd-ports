# New ports collection makefile for:		opera
# Date created:					November 5th 2000
# Whom:						des
#
# $FreeBSD$
#

PORTNAME=	opera
PORTVERSION=	${OPERA_VER}.${OPERA_DATE}
CATEGORIES=	www ipv6
MASTER_SITES=	ftp://ftp.opera.com/pub/opera/unix/freebsd/${OPERA_VER:S/.//}${OPERA_MINVER}/${OPERA_REL}/en/${OPERA_LIB}/ \
		http://T32.TecNik93.com/FreeBSD/others_ports/${PORTNAME}${PKGNAMESUFFIX}/sources/ \
		ftp://opera.inode.at/unix/freebsd/${OPERA_VER:S/.//}${OPERA_MINVER}/${OPERA_REL}/en/${OPERA_LIB}/ \
		http://gd.tuwien.ac.at/infosys/browsers/opera/unix/freebsd/${OPERA_VER:S/.//}${OPERA_MINVER}/${OPERA_REL}/en/${OPERA_LIB}/ \
		http://ftp.ucr.ac.cr/WWW/opera/unix/freebsd/${OPERA_VER:S/.//}${OPERA_MINVER}/${OPERA_REL}/en/${OPERA_LIB}/ \
		http://www.microrpm.ca/pub/opera/unix/freebsd/${OPERA_VER:S/.//}${OPERA_MINVER}/${OPERA_REL}/en/${OPERA_LIB}/ \
		http://www.opera.mirroarrr.de/unix/freebsd/${OPERA_VER:S/.//}${OPERA_MINVER}/${OPERA_REL}/en/${OPERA_LIB}/ \
		http://opera.eurenet.net/unix/freebsd/${OPERA_VER:S/.//}${OPERA_MINVER}/${OPERA_REL}/en/${OPERA_LIB}/ \
		ftp://opera.ftp.fu-berlin.de/unix/freebsd/${OPERA_VER:S/.//}${OPERA_MINVER}/${OPERA_REL}/en/${OPERA_LIB}/ \
		http://ftp.ntua.gr/pub/www/Opera/unix/freebsd/${OPERA_VER:S/.//}${OPERA_MINVER}/${OPERA_REL}/en/${OPERA_LIB}/ \
		ftp://ftp.wayne.edu/opera/unix/freebsd/${OPERA_VER:S/.//}${OPERA_MINVER}/${OPERA_REL}/en/${OPERA_LIB}/ \
		http://mirrors.dedipower.com/opera/unix/freebsd/${OPERA_VER:S/.//}${OPERA_MINVER}/${OPERA_REL}/en/${OPERA_LIB}/ \
		ftp://ftp.mirror.ac.uk/sites/ftp.opera.com/unix/freebsd/${OPERA_VER:S/.//}${OPERA_MINVER}/${OPERA_REL}/en/${OPERA_LIB}/ \
		http://opera.nedmirror.nl/unix/freebsd/${OPERA_VER:S/.//}${OPERA_MINVER}/${OPERA_REL}/en/${OPERA_LIB}/ \
		ftp://ftp.tiscali.nl/pub/mirrors/opera/unix/freebsd/${OPERA_VER:S/.//}${OPERA_MINVER}/${OPERA_REL}/en/${OPERA_LIB}/ \
		${MASTER_SITE_RINGSERVER:S,%SUBDIR%,net/www/opera/unix/freebsd/${OPERA_VER:S/.//}${OPERA_MINVER}/${OPERA_REL}/en/${OPERA_LIB}/&,} \
		ftp://ftp.opera.com/pub/opera/unix/freebsd/${OPERA_VER:S/.//}${OPERA_MINVER}/${OPERA_REL}/en/${OPERA_LIB}/ \
		http://T32.TecNik93.com/FreeBSD/others_ports/${PORTNAME}${PKGNAMESUFFIX}/sources/
DISTNAME=	${PORTNAME}-${OPERA_VER}${OPERA_MINVER}-freebsd${OPERA_TYPE}-shared-qt3.${ARCH}

MAINTAINER=	freebsd-maintainer@opera.com
COMMENT=	Blazingly fast, full-featured, standards-compliant browser, devel version

OPERA_VER=	9.51
OPERA_MINVER=
OPERA_REL=	final
OPERA_DATE=	20080630
OPERA_BUILD=	2061

DATADIR=	${PREFIX}/share/${PORTNAME}${PKGNAMESUFFIX}
DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}${PKGNAMESUFFIX}

USE_BZIP2=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${OPERA_VER}-${OPERA_BUILD}.freebsd${OPERA_TYPE}-shared-qt3.${ARCH}
USE_QT_VER=	3

MAN1=		opera.1

NO_BUILD=	yes

OPTIONS=	ASPELL	"Use the aspell library for spell checking"	on

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 600000
ONLY_FOR_ARCHS=	i386 amd64
.else
ONLY_FOR_ARCHS=	i386
.endif

.if ${ARCH} == amd64
OPERA_LIB=	amd64
.else
OPERA_LIB=	shared
.endif

.if ${OSVERSION} >= 700000
OPERA_TYPE=	7
.elif ${OSVERSION} >= 600000
OPERA_TYPE=	6
.elif ${OSVERSION} >= 500000
OPERA_TYPE=	5
.else
IGNORE=	is only supported on FreeBSD 5.x and higher
.endif

.if !defined(WITHOUT_ASPELL)
LIB_DEPENDS+=	aspell.16:${PORTSDIR}/textproc/aspell
.endif

do-install:
	@(cd ${WRKSRC} && ./install.sh --prefix=${PREFIX} --docdir=${DOCSDIR} --sharedir=${DATADIR} --exec_prefix=${DATADIR}/bin --plugindir=${DATADIR}/plugins)

.include <bsd.port.post.mk>
