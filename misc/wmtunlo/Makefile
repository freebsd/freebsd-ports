# New ports collection makefile for:	wmtunlo
# Date created:			27 July 2002
# Whom:				Adam Weinberger <adam@vectors.cx>
#
# $FreeBSD$
#

PORTNAME=	wmtunlo
PORTVERSION=	0.1.1
CATEGORIES=	misc windowmaker
MASTER_SITES=	http://clay.ll.pl/download/

MAINTAINER=	adamw@FreeBSD.org

PORTCOMMENT=	A bo(O)oooring 2d tunnel in wmaker dock

USE_REINPLACE=	yes
USE_X_PREFIX=	yes
USE_XPM=	yes

post-patch:
.for i in 1 2 3 4 5
	@${REINPLACE_CMD} -e 's|./wmtunlo|${PREFIX}/bin/wmtunlo|g' \
		${WRKSRC}/example${i}
.endfor

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/wmtunlo ${PREFIX}/bin
	@${MKDIR} ${EXAMPLESDIR}
.for i in 1 2 3 4 5
	@${INSTALL_SCRIPT} ${WRKSRC}/example${i} \
		${EXAMPLESDIR}/wmtunlo.example${i}
.endfor

.include <bsd.port.mk>
