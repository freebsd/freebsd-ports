PORTNAME=	portupdate-scan
PORTVERSION=	0.4
PORTREVISION=	1
CATEGORIES=	ports-mgmt
MASTER_SITES=	# none
DISTFILES=	# none

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Display pertinent parts of {PORTSDIR}/UPDATING

LICENSE=	ISCL

DEPRECATED=	Likely out of date and not very useful

NO_BUILD=	yes
USES=		perl5 shebangfix
USE_PERL5=	run

PLIST_FILES=	sbin/portupdate-scan share/man/man8/portupdate-scan.8.gz
SHEBANG_FILES=	portupdate-scan
SRC=		${.CURDIR}/src

do-extract:
	@${MKDIR} ${WRKSRC}
	@${CP} ${SRC}/${PORTNAME} ${SRC}/${PORTNAME}.8 ${WRKSRC}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.8 ${STAGEDIR}${PREFIX}/share/man/man8

.include <bsd.port.mk>
