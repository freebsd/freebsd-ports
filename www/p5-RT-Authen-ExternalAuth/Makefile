# Created by: Matthew Seaman
# $FreeBSD$

PORTNAME=	RT-Authen-ExternalAuth
DISTVERSION=	0.27
CATEGORIES=	www net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	matthew@FreeBSD.org
COMMENT=	RT42 extension to authenticate users against an external source

LICENSE=	GPLv2

BUILD_DEPENDS=	p5-perl-ldap>0:net/p5-perl-ldap \
		p5-DBI>0:databases/p5-DBI \
		p5-Net-SSLeay>0:security/p5-Net-SSLeay \
		${LOCALBASE}/bin/rt:www/rt${RT_VER}
RUN_DEPENDS=	p5-perl-ldap>0:net/p5-perl-ldap \
		p5-DBI>0:databases/p5-DBI \
		p5-Net-SSLeay>0:security/p5-Net-SSLeay \
		${LOCALBASE}/bin/rt:www/rt${RT_VER}

USES+=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

# This module has been made part of core rt-4.4.x
CONFLICTS_INSTALL=	rt44
RT_VER=		42

MAN3PREFIX=	${PREFIX}

PLIST_SUB+=	RTHOME=share/rt${RT_VER}

# Note: You can install using an arbitrary $PREFIX but only if it
# matches the $PREFIX used to install www/rt42.  Hence ignore
# $PREFIX in the environment and inherit settings from RT.pm

do-configure:
	@cd ${CONFIGURE_WRKSRC} && \
	    unset PREFIX && \
	    ${SETENV} ${CONFIGURE_ENV} ${PERL5} -I${SITE_PERL} ${CONFIGURE_CMD} && \
	    ${PERL5} -pi -e 's/ doc_(perl|site|\$$\(INSTALLDIRS\))_install$$//;' Makefile

post-configure:
	${REINPLACE_CMD} "/RTxPlugin/d" ${WRKSRC}/Makefile

post-install:
	${RM} ${STAGEDIR}${PREFIX}/man/auto/RT/Authen/ExternalAuth/.packlist
	${RMDIR} -p ${STAGEDIR}${PREFIX}/man/auto/RT/Authen/ExternalAuth 2>/dev/null || :

.include <bsd.port.mk>
