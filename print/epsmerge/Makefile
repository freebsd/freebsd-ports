# New ports collection makefile for:	epsmerge
# Date created:				Nov 30, 2003
# Whom:					Bruce M Simpson <bms@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	epsmerge
PORTVERSION=	2.2.2
CATEGORIES=	print
MASTER_SITES=	http://home.clara.net/nox/software/epsmerge/
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	bms@FreeBSD.org
COMMENT=	Merge multiple EPS files into one EPS or PS file

USE_PERL5=	yes
USE_REINPLACE=	yes
USE_SUBMAKE=	yes
NO_BUILD=	yes

MAN1=		epsmerge.1

EPSMERGELIBDIR=	${PREFIX}/lib/${PORTNAME}

LIBFILES=	Cell.pm CellFactory.pm Driver.pm Eps.pm Formatter.pm \
		Io.pm MainCell.pm Options.pm

do-install:
	${MKDIR} ${EPSMERGELIBDIR}
.for libfile in ${LIBFILES}
	${INSTALL_SCRIPT} ${WRKSRC}/lib/${libfile} ${EPSMERGELIBDIR}
.endfor
	${INSTALL_SCRIPT} ${WRKSRC}/epsmerge ${EPSMERGELIBDIR}
	${REINPLACE_CMD} -e 's|/usr/bin/perl|${PERL5}|g' \
	    ${EPSMERGELIBDIR}/epsmerge
	${RM} ${EPSMERGELIBDIR}/epsmerge.bak
	${INSTALL_SCRIPT} ${FILESDIR}/epsmerge ${PREFIX}/bin
	${REINPLACE_CMD} -e 's|%%EPSMERGELIBDIR%%|${EPSMERGELIBDIR}|g' \
	    ${PREFIX}/bin/epsmerge
	${RM} ${PREFIX}/bin/epsmerge.bak
.if !defined(NO_INSTALL_MANPAGES)
	${INSTALL_MAN} ${WRKSRC}/docs/${PORTNAME}.1 ${PREFIX}/man/man1
.endif
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/docs/${PORTNAME}.txt ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/docs/${PORTNAME}.html ${DOCSDIR}
.endif

.include <bsd.port.mk>
