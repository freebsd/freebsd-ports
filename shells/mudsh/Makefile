# New ports collection makefile for:   mudsh
# Date created:        28 February 2001
# Whom:                George Reid <greid@ukug.uk.freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	mudsh
PORTVERSION=	20010311
CATEGORIES=	shells
MASTER_SITES=	http://www.xirium.com/tech/mud-shell/download/
DISTNAME=	mudsh
EXTRACT_SUFX=
EXTRACT_ONLY=

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An "intelligent" game-like shell

NO_WRKSUBDIR=	yes

NO_BUILD=	yes

post-extract:
	@${CP} ${DISTDIR}/${DISTNAME} ${WRKSRC}

do-patch:
	@(${SED} -e 's,/usr/local/bin/perl,${PERL},1' ${WRKSRC}/${DISTNAME} \
		> ${WRKDIR}/foo && ${MV} ${WRKDIR}/foo ${WRKSRC}/${DISTNAME})

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${DISTNAME} ${PREFIX}/bin

post-install:
	@${ECHO} "updating /etc/shells"
	@${CP} /etc/shells /etc/shells.bak
	@(${GREP} -v ${PREFIX}/bin/mudsh /etc/shells.bak; \
	 ${ECHO_CMD} ${PREFIX}/bin/mudsh) > /etc/shells
	@${RM} /etc/shells.bak

.include <bsd.port.mk>
