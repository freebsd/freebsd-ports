# New ports collection makefile for:	amsn
# Date created:		01 Feb 2003
# Whom:			Andreas Klemm <andreas@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	amsn
PORTVERSION=	0.71
CATEGORIES=	net
MASTER_SITES=	http://download.sourceforge.net/${PORTNAME}/

MAINTAINER=	ports@FreeBSD.org

RUN_DEPENDS=	wish8.4:${PORTSDIR}/x11-toolkits/tk84

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/msn
USE_PERL5_BUILD=yes

LIBDIR=		${PREFIX}/lib/msn
DOCSDIR=	${PREFIX}/share/doc/amsn
CORE=		FAQ HELP README amsn jwakeup langlist *tcl *htm*
SUBDIR=		i lang s
DOC_FILES=	LEEME TODO changelog

do-install:
	@${MKDIR} ${LIBDIR}
	@cd ${WRKSRC}; tar cf - ${CORE} | ( cd ${LIBDIR}; tar xpf - )
.for i in ${SUBDIR}
	@cd ${WRKSRC}; tar cf - ${i} | ( cd ${LIBDIR}; tar xpf - )
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in ${DOC_FILES}
	@${INSTALL_MAN} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

post-install:
	@sed -e "s=!!PREFIX!!=${PREFIX}=" < ${FILESDIR}/amsn \
		> ${PREFIX}/bin/amsn
	@${CHMOD} 555 ${PREFIX}/bin/amsn
	@${CHMOD} 555 ${PREFIX}/lib/msn/amsn

.include <bsd.port.mk>
