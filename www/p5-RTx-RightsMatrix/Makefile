# New ports collection Makefile for: RTx-Calendar
# Date created:	        24 August 2008
# Whom:                 Matthew Seaman <m.seaman@infracaninophile.co.uk>
#
# $FreeBSD$
#

PORTNAME=	RTx-RightsMatrix
PORTVERSION=	0.03.00
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
EXTRACT_SUFX=	.tgz

MAINTAINER=	m.seaman@infracaninophile.co.uk
COMMENT=	Bulk editing GUI for RT rights

BUILD_DEPENDS=	${LOCALBASE}/${RTHOME}/bin/rt:${PORTSDIR}/www/rt36
RUN_DEPENDS=	${BUILD_DEPENDS}

RTHOME?=	rt3
PLIST_SUB+=	RTHOME=${RTHOME}

PERL_CONFIGURE=	yes
CONFIGURE_ENV+=	RTHOME=${PREFIX}/${RTHOME}

MAN3=		RTx::RightsMatrix::RolePrincipal.3 \
		RTx::RightsMatrix::Util.3          \
		RTx::RightsMatrix.3

# Don't use normal CONFIGURE_ARGS.  Disable doc_?????_indstall targets to
# suppress installing perllocal.pod.  This duplicates code from bsd.perl.mk
# rather undesirably.
do-configure:
	@cd ${CONFIGURE_WRKSRC} && \
	    ${SETENV} ${CONFIGURE_ENV} ${PERL5} ./${CONFIGURE_SCRIPT} && \
	    ${PERL5} -pi -e 's/ doc_(perl|site|\$$\(INSTALLDIRS\))_install$$//' Makefile

.include <bsd.port.mk>
