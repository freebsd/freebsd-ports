# New ports collection makefile for:   spambnc
# Date created:        25 December 2000
# Whom:                George Reid <greid@ukug.uk.freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	spambnc
PORTVERSION=	20010805
CATEGORIES=	mail
MASTER_SITES=	http://www.spambouncer.org/
DISTFILES=	sb.tar.Z index.shtml
DIST_SUBDIR=	spambnc
EXTRACT_ONLY=	sb.tar.Z

MAINTAINER=	greid@FreeBSD.org

IGNOREFILES=	index.shtml
NO_WRKSUBDIR=	yes
NO_BUILD=	yes

SBFILES=	check-blacklists.rc freemail legitlists notify procmail.rc \
		sb-blacklists.rc sb-blockheaders.rc sb-blockisps.rc \
		sb-blocksw.rc sb-domain_from_forgeries.rc sb-fraud.rc \
		sb-freemail.rc sb-ideological.rc sb-languages.rc \
		sb-mainsleaze.rc sb-ordinary.rc sb-pt-bogus_urls.rc \
		sb-pt-bulk_email_advertising.rc sb-pt-chain_letters.rc \
		sb-pt-credit.rc sb-pt-detective.rc sb-pt-diploma.rc \
		sb-pt-disclaimer.rc sb-pt-havendomains.rc sb-pt-health.rc \
		sb-pt-html.rc sb-pt-mmf.rc sb-pt-onlinebiz.rc \
		sb-pt-other_patterns.rc sb-pt-scripts.rc sb-pt-spamphone.rc \
		sb-pt-spampostal.rc sb-pt-spamsubjects.rc sb-pt-stock.rc \
		sb-pt-webhost.rc sb-pt-websitetraffic.rc sb-pt-websurf.rc \
		sb-pt-weight_loss.rc sb-pt-work_from_home.rc sb-pt-xxx.rc \
		sb-retired.rc sb-rogue.rc sb-smallfry.rc sb-spamforhire.rc \
		sb-spamheaders.rc sb-spamisps.rc sb-spamsw.rc sb-viruses.rc \
		sb.rc spam

do-install:
	${MKDIR} ${PREFIX}/share/spambnc/
.for FILE in ${SBFILES}
	${INSTALL_DATA} ${WRKSRC}/${FILE} ${PREFIX}/share/spambnc/
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/spambnc/
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/index.shtml \
		${PREFIX}/share/doc/spambnc/documentation.html
.endif

post-install:
	@${SED} -e 's,%%PREFIX%%,${PREFIX},g' ${PKGMESSAGE}

.include <bsd.port.mk>
