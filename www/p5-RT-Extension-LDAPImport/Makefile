# New ports collection Makefile for: RT-Extension-LDAPImport
# Date created:	        24 August 2008
# Whom:                 Matthew Seaman <m.seaman@infracaninophile.co.uk>
#
# $FreeBSD$
#

PORTNAME=	RT-Extension-LDAPImport
PORTVERSION=	0.04
PORTREVISION=	1
CATEGORIES=	www net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	m.seaman@infracaninophile.co.uk
COMMENT=	RT extension to import users from an LDAP store

BUILD_DEPENDS=	${LOCALBASE}/${RTHOME}/bin/rt:${PORTSDIR}/www/rt36 \
		${SITE_PERL}/Net/LDAP.pm:${PORTSDIR}/net/p5-perl-ldap \
		${SITE_PERL}/Class/Accessor.pm:${PORTSDIR}/devel/p5-Class-Accessor
RUN_DEPENDS=	${BUILD_DEPENDS}

RTHOME?=	rt3
PLIST_SUB+=	RTHOME=${RTHOME}

PERL_CONFIGURE=	yes
CONFIGURE_ENV+=	RTHOME=${PREFIX}/${RTHOME}

MAN3=		RT::Extension::LDAPImport.3

post-patch:
	@${REINPLACE_CMD} -e 's,/opt/rt3/lib,${PREFIX}/${RTHOME}/lib,' \
	    ${WRKSRC}/bin/rtldapimport && \
	    ${RM} ${WRKSRC}/bin/rtldapimport.bak

# Don't use normal CONFIGURE_ARGS.  Disable doc_?????_indstall targets to
# suppress installing perllocal.pod.  This duplicates code from bsd.perl.mk
# rather undesirably.
do-configure:
	@cd ${CONFIGURE_WRKSRC} && \
	    ${SETENV} ${CONFIGURE_ENV} ${PERL5} ./${CONFIGURE_SCRIPT} && \
	    ${PERL5} -pi -e 's/ doc_(perl|site|\$$\(INSTALLDIRS\))_install$$//' Makefile

.include <bsd.port.mk>
