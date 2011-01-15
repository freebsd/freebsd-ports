# New ports collection makefile for:	hardlink
# Date created:				14 January 2011
# Whom:					Douglas Thrift
#
# $FreeBSD$
#

PORTNAME=	hardlink
PORTVERSION=	0.1.1
CATEGORIES=	sysutils python
MASTER_SITES=	http://jak-linux.org/projects/hardlink/ \
		http://apt.douglasthrift.net/files/${PORTNAME}/ \
		http://code.douglasthrift.net/files/${PORTNAME}/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	douglas@douglasthrift.net
COMMENT=	Replace file copies using hardlinks

LICENSE=	MIT

MAN1=		hardlink.1
NO_BUILD=	yes
PLIST_FILES=	bin/hardlink
USE_PYTHON=	2.5+
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/bin/python|${PYTHON_CMD}|' ${WRKSRC}/hardlink.py

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/hardlink.py ${PREFIX}/bin/hardlink
	${INSTALL_MAN} ${WRKSRC}/hardlink.1 ${PREFIX}/man/man1/hardlink.1

.include <bsd.port.mk>
