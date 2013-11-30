# Created by: kline
# $FreeBSD$

PORTNAME=	enscriptfonts
PORTVERSION=	0.81
CATEGORIES=	print
MASTER_SITES=	http://muuz.deadbbs.com/FreeBSD/xenscript/
DISTNAME=	enscript_fonts-0.81
EXTRACT_SUFX=	.tbz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	More than 120 free- and share-ware fonts to extend enscript-1.5

NO_WRKSUBDIR=	YES
NO_MANCOMPRESS=	YES
NO_BUILD=	YES
SUB_FILES+=	pkg-message

# user should choose their own version
#RUN_DEPENDS=	enscript:${PORTSDIR}/print/enscript-letter

NO_STAGE=	yes
do-install:
	@${MKDIR} ${PREFIX}/share/enscript/xenscript
	@${CP} -p ${WRKDIR}/* ${PREFIX}/share/enscript/xenscript

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
