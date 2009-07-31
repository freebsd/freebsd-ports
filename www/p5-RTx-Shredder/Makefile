# New ports collection Makefile for: RTx-Shredder
# Date created:	        23 August 2008
# Whom:                 Matthew Seaman <m.seaman@infracaninophile.co.uk>
#
# $FreeBSD$
#

PORTNAME=	RTx-Shredder
PORTVERSION=	0.07
PORTREVISION=	2
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	m.seaman@infracaninophile.co.uk
COMMENT=	Cleanup RT database

BUILD_DEPENDS=	${LOCALBASE}/${RTHOME}/bin/rt:${PORTSDIR}/www/rt36 \
		p5-DBIx-SearchBuilder>=1.31:${PORTSDIR}/databases/p5-DBIx-SearchBuilder \
		p5-Exception-Class>=1.23:${PORTSDIR}/devel/p5-Exception-Class \
		${SITE_PERL}/${PERL_ARCH}/DBD/SQLite.pm:${PORTSDIR}/databases/p5-DBD-SQLite \
		${SITE_PERL}/Test/Deep.pm:${PORTSDIR}/devel/p5-Test-Deep
RUN_DEPENDS=	${BUILD_DEPENDS}

RTHOME?=	rt3
PLIST_SUB+=	RTHOME=${RTHOME}

PERL_CONFIGURE=	yes
CONFIGURE_ENV+=	RTHOME=${PREFIX}/${RTHOME}

MAN3=		RTx::Shredder.3				\
		RTx::Shredder::Constants.3		\
		RTx::Shredder::Dependencies.3		\
		RTx::Shredder::Plugin.3			\
		RTx::Shredder::Plugin::Attachments.3	\
		RTx::Shredder::Plugin::Base.3		\
		RTx::Shredder::Plugin::Objects.3	\
		RTx::Shredder::Plugin::Tickets.3	\
		RTx::Shredder::Plugin::Users.3		\
		RTx::Shredder::Record.3

# Don't use normal CONFIGURE_ARGS.  Disable doc_?????_indstall targets to
# suppress installing perllocal.pod.  This duplicates code from bsd.perl.mk
# rather undesirably.
do-configure:
	@cd ${CONFIGURE_WRKSRC} && \
	    ${SETENV} ${CONFIGURE_ENV} ${PERL5} ./${CONFIGURE_SCRIPT} && \
	    ${PERL5} -pi -e 's/ doc_(perl|site|\$$\(INSTALLDIRS\))_install$$//' Makefile

.include <bsd.port.mk>
