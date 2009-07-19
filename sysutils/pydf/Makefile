# New ports collection makefile for:	pydf
# Date created:				29 November 2007
# Whom:					Baptiste Grenier <gwarf@gwarf.org>
#
# $FreeBSD$
#

PORTNAME=	pydf
PORTVERSION=	7
CATEGORIES=	sysutils
MASTER_SITES=	http://kassiopeia.juls.savba.sk/~garabik/software/pydf/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	gwarf@gwarf.org
COMMENT=	A python implementation of df

SUB_FILES=	pkg-message

PLIST_FILES=	bin/pydf etc/pydfrc.sample

USE_PYTHON=	true
NO_BUILD=	yes

MAN1=		pydf.1
MANCOMPRESSED=	no

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

post-patch:
	@${REINPLACE_CMD} -e 's|%%PYTHON_CMD%%|${PYTHON_CMD}| ; s|%%PREFIX%%|${PREFIX}|' ${WRKSRC}/pydf

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/pydf ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/pydfrc ${PREFIX}/etc/pydfrc.sample
	${INSTALL_MAN} ${WRKSRC}/pydf.1 ${PREFIX}/man/man1

post-install:
	@if [ ! -f ${PREFIX}/etc/pydfrc ]; then \
		${ECHO_MSG} ; \
		${CAT} ${PKGMESSAGE} ; \
		${ECHO_MSG} ; \
	fi

.include <bsd.port.mk>
