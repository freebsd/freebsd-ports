# New ports collection makefile for:	uvscan
# Date created:		01 Sep 2000
# Whom:			Kris Kennaway <kris@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	uvscan
PORTVERSION=	4.40e
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://download.nai.com/products/evaluation/virusscan/english/cmdline/bsd/v4.40/
DISTNAME=	vbsd440e
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	jeh@FreeBSD.org
COMMENT=	Evaluation version of a DOS/Windows/Linux file virus scanner

RUN_DEPENDS+=	${LOCALBASE}/sbin/update_dat:${PORTSDIR}/security/uvscan-dat
# misc/compat3x is forbidden, but if it is compiled into the system
# we may still be good to go.
LIB_DEPENDS+=	c.3:${PORTSDIR}/misc/compat3x
LIB_DEPENDS+=	m.2:${PORTSDIR}/misc/compat4x

ONLY_FOR_ARCHS=		i386
NO_BUILD=		YES
NO_WRKSUBDIR=		YES
INSTALLS_SHLIB=		YES

LICENSE=	shareware
RESTRICTED=	"restrictive 30 day evaluation license"

MAN1=		uvscan.1

PORTDOCS=	e4400upg.pdf readme.txt

PROGFILES=	contact.txt license.dat license.txt messages.dat \
		signlic.txt

do-configure:
	${SED} <${FILESDIR}/uvscan.sh >${WRKSRC}/uvscan.sh \
		-e 's:@@PREFIX@@:${PREFIX}:g'

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/uvscan ${PREFIX}/libexec/uvscan
	${INSTALL_SCRIPT} ${WRKSRC}/uvscan.sh ${PREFIX}/bin/uvscan
	${INSTALL_SCRIPT} ${WRKSRC}/uvscan_secure ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/libbsdfv.so.4 ${PREFIX}/lib/libbsdfv.so.4
.for filename in ${PROGFILES}
	${INSTALL_DATA} ${WRKSRC}/${filename} ${PREFIX}/libexec/uvscan
.endfor
.for filename in ${MAN1}
	${INSTALL_MAN} ${WRKSRC}/${filename} ${MANPREFIX}/man/man1/${filename}
.endfor
.if !defined(NOPORTDOCS)
	@if ! [ -d ${DOCSDIR} ]; then ${MKDIR} ${DOCSDIR}; fi
.for filename in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${filename} ${DOCSDIR}
.endfor
.endif

post-install:
	${LN} -sf ${PREFIX}/lib/libbsdfv.so.4 \
		${PREFIX}/lib/libbsdfv.so

.include <bsd.port.mk>
