# New ports collection makefile for:	FURI Gnutella client
# Date created:		31 Mar 2001
# Whom:			Mario Sergio Fujikawa Ferreira <liouxFreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	furi
PORTVERSION=	0.68
CATEGORIES=	net java
MASTER_SITES=	http://www.jps.net/williamw/furi/
DISTNAME=	${PORTNAME}${PORTVERSION:S/.//}

MAINTAINER=	lioux@FreeBSD.org

RUN_DEPENDS=	${JAVAVM}:${PORTSDIR}/java/javavmwrapper \
		${LOCALBASE}/etc/javavms:${PORTSDIR}/java/jre \
		${LOCALBASE}/share/java/classes/jfc-1.1.1/swing.jar:${PORTSDIR}/java/jfc

USE_ZIP=	yes
USE_XLIB=	yes
NO_WRKSUBDIR=	yes
NO_BUILD=	yes

JAVAVM=		${LOCALBASE}/bin/javavm
INSTSBDR=	${PREFIX}/share/java/classes/furi
INSTALL_DIR=	${INSTALL} -d -o ${SHAREOWN} -g ${SHAREGRP} -m 0555

post-extract:
	@${SED} -e "s!/usr/local!${LOCALBASE}!" ${FILESDIR}/furi.sh > ${WRKSRC}/furi.sh

post-patch:
	@${PERL} -pi -ne "s!!!" ${WRKSRC}/Readme.txt

do-install:
	@${INSTALL_DIR} ${INSTSBDR} ${PREFIX}/share/doc/${PORTNAME}
	@${INSTALL_DATA} ${WRKSRC}/furi.jar ${INSTSBDR}
	@${INSTALL_DATA} ${WRKSRC}/Readme.txt ${PREFIX}/share/doc/${PORTNAME}
	@${INSTALL_SCRIPT} ${WRKSRC}/furi.sh ${PREFIX}/bin/furi

.include <bsd.port.mk>
