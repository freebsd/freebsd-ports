# ex:ts=8
# Ports collection makefile for:	mftrace (formerly pktrace)
# Date created:			Jun w, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	mftrace
PORTVERSION=	1.0.19
CATEGORIES=	print
MASTER_SITES=	http://www.xs4all.nl/~hanwen/mftrace/

MAINTAINER=	trevor@FreeBSD.org
COMMENT=	Scalable PostScript (Type1) Fonts for MetaFont

RUN_DEPENDS=	mktextfm:${PORTSDIR}/print/teTeX \
		autotrace:${PORTSDIR}/graphics/autotrace \
		t1asm:${PORTSDIR}/print/t1utils \
		pfaedit:${PORTSDIR}/print/pfaedit

USE_GETOPT_LONG=yes
USE_PYTHON=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
MAKEFILE=	GNUmakefile
PLIST=		${WRKDIR}/pkg-plist
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

MAN1=	mftrace.1

pre-everything::
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD} Pausing ten seconds--press control-C to cancel build.
	@sleep 10

pre-install:
	${RM} -f ${PLIST}
.for ii in gf2pbm mftrace
	${ECHO_CMD} bin/${ii} >> ${PLIST}
.endfor
.for ii in afm tfm
	${ECHO_CMD} lib/%%PYTHON_VERSION%%/site-packages/${ii}.py >> ${PLIST}
.endfor

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gf2pbm ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/mftrace ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/mftrace.1 ${MANPREFIX}/man/man1
	${INSTALL_SCRIPT} ${WRKSRC}/tfm.py ${PYTHON_SITELIBDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/afm.py ${PYTHON_SITELIBDIR}

.include <bsd.port.mk>
