# New ports collection makefile for:   gtkgrepmail
# Date created:        19 May 2002
# Whom:                Oliver Braun <obraun@informatik.unibw-muenchen.de>
#
# $FreeBSD$
#

PORTNAME=	gtkgrepmail
PORTVERSION=	0.6
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.terminus.net.au/unix/perl/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org

BUILD_DEPENDS=	grepmail:${PORTSDIR}/mail/grepmail \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/Gnome.pm:${PORTSDIR}/x11-toolkits/p5-Gnome \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Date/Manip.pm:${PORTSDIR}/devel/p5-Date-Manip \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/URI.pm:${PORTSDIR}/net/p5-URI
RUN_DEPENDS=	grepmail:${PORTSDIR}/mail/grepmail \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/Gnome.pm:${PORTSDIR}/x11-toolkits/p5-Gnome \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Date/Manip.pm:${PORTSDIR}/devel/p5-Date-Manip \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/URI.pm:${PORTSDIR}/net/p5-URI

PERL_CONFIGURE=	YES

MAN1=		gtkgrepmail.1

PORTDOCS=	COPYING FAQ NEWS ROADMAP changelog INSTALL README TODO

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
.for file in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/Documentation/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
