# ex:ts=8
# Ports collection makefile for:  aub
# Date created:			  Sun Oct 12, 1997
# Whom:				  David O'Brien (obrien@cs.ucdavis.edu)
#
# $FreeBSD$
#

PORTNAME=	aub
PORTVERSION=	2.0.5
CATEGORIES=	news
MASTER_SITES=	ftp://ftp.freesoftware.com/pub/perl/CPAN/scripts/news/nntpstuff/aub/ \
		ftp://ftp.digital.com/pub/plan/perl/CPAN/scripts/news/nntpstuff/aub/ \
		ftp://ftp.perl.org/pub/CPAN/scripts/news/nntpstuff/aub/
DISTFILES=	aub aub.1 BUG_FIXES

MAINTAINER=	obrien@FreeBSD.org

DIST_SUBDIR=	aub
NO_WRKSUBDIR=	yes
NO_BUILD=	yes
MAN1=		aub.1

do-extract:
	@${MKDIR} ${WRKDIR}

pre-patch:
	@${SED} -e '1,1s:/usr/local/bin/perl:!${PERL5}:' \
		-e 's:$SUM = "/bin/sum":$SUM = "/usr/bin/sum":' \
		-e 's:/usr/tmp:/var/tmp:' \
		${DISTDIR}/${DIST_SUBDIR}/aub > ${WRKDIR}/aub

.if !exists(/usr/bin/perl5)
post-patch:
	@cd ${WRKSRC} ; ${PATCH} -d ${WRKSRC} --reverse --quiet -E \
		${PATCH_STRIP} < ${PATCHDIR}/patch-01
.endif

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/aub ${PREFIX}/bin
	${INSTALL_MAN} ${DISTDIR}/${DIST_SUBDIR}/aub.1 ${PREFIX}/man/man1
	${MKDIR} ${PREFIX}/share/doc/aub
	${INSTALL_MAN} ${DISTDIR}/${DIST_SUBDIR}/BUG_FIXES ${PREFIX}/share/doc/aub

.include <bsd.port.mk>
