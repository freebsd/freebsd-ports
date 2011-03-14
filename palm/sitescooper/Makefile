# Ports collection makefile for:	sitescooper
# Date created:			31 May 2001
# Whom:				dom@happygiraffe.net
#
# $FreeBSD$
#

PORTNAME=	sitescooper
PORTVERSION=	3.1.2
PORTREVISION=	2
CATEGORIES=	palm
MASTER_SITES=	http://sitescooper.org/released/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	News site downloader for Palm computing devices

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/HTML/Parser.pm:${PORTSDIR}/www/p5-HTML-Parser \
		${SITE_PERL}/LWP.pm:${PORTSDIR}/www/p5-libwww \
		${SITE_PERL}/URI/URL.pm:${PORTSDIR}/net/p5-URI \
		${SITE_PERL}/Algorithm/Diff.pm:${PORTSDIR}/devel/p5-Algorithm-Diff

USE_PERL5=	yes
NO_BUILD=	yes
MAN1=		rss-to-site.1 sitescooper.1 subs-to-site.1

post-patch:
	${RM} ${WRKSRC}/lib/Sitescooper/Main.pm.orig
	${PERL} -pi -e "s|^#!.+|#!${PERL}|; \
		s|/usr/local/etc/sitescooper.cf|${PREFIX}/etc/sitescooper.cf|g; \
		s|/usr/local/etc/sitescooper/sitescooper.cf|${PREFIX}/etc/sitescooper.cf.sample|g;" ${WRKSRC}/*.pl
	${ECHO_CMD} "MakeDoc: pilot_makedoc" >> ${WRKSRC}/sitescooper.cf
	${ECHO_CMD} "iSilo: iSiloBSD" >> ${WRKSRC}/sitescooper.cf
	${ECHO_CMD} "SitescooperDir: ${PREFIX}/share/sitescooper" >> \
		${WRKSRC}/sitescooper.cf

do-install:
.for F in sitescooper rss-to-site subs-to-site
	${INSTALL_SCRIPT} ${WRKSRC}/${F}.pl ${PREFIX}/bin/${F}
	${INSTALL_MAN} ${WRKSRC}/doc/${F}.man ${PREFIX}/man/man1/${F}.1
.endfor
	${INSTALL_DATA} ${WRKSRC}/sitescooper.cf \
		${PREFIX}/etc/sitescooper.cf.sample
	${MKDIR} ${PREFIX}/share/${PORTNAME}
.for D in Exten PDA Sitescooper
	${MKDIR} ${SITE_PERL}/${D}
	${INSTALL_DATA} ${WRKSRC}/lib/${D}/* ${SITE_PERL}/${D}
.endfor
	(cd ${WRKSRC}; ${FIND} profile_samples site_samples -type d \
		-exec ${MKDIR} "${PREFIX}/share/sitescooper/{}" \;)
	(cd ${WRKSRC}; ${FIND} profile_samples site_samples -type f \
		-exec ${INSTALL_DATA} "{}" "${PREFIX}/share/sitescooper/{}" \;)
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/${PORTNAME}
.for F in contributing.html running.html site_params.html writing_site.html
	${INSTALL_DATA} ${WRKSRC}/doc/${F} ${PREFIX}/share/doc/${PORTNAME}
.endfor
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
