# Created by: Florent Thoumie <flz@xbsd.org>
# $FreeBSD$

PORTNAME=	ldapsh
PORTVERSION=	2.00
PORTREVISION=	4
PORTEPOCH=	1
CATEGORIES=	net
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:LOOSIFER

MAINTAINER=	flz@FreeBSD.org
COMMENT=	Interactive shell used to administer ldap directories

BUILD_DEPENDS=	p5-Term-ReadKey>=0:devel/p5-Term-ReadKey \
		p5-Term-ReadLine-Perl>=0:devel/p5-Term-ReadLine-Perl \
		p5-perl-ldap>=0:net/p5-perl-ldap \
		p5-Date-Manip>=0:devel/p5-Date-Manip \
		p5-ParseLex>=0:devel/p5-ParseLex
RUN_DEPENDS:=	${BUILD_DEPENDS}

SUB_FILES=	pkg-message

USES=		perl5 shebangfix
USE_PERL5=	configure
SHEBANG_FILES=	ldapsh

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/COMMANDS ${STAGEDIR}${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/examples/ldapsh_config ${STAGEDIR}${EXAMPLESDIR}/

.include <bsd.port.mk>
