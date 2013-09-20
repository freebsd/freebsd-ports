# Created by: Florent Thoumie <flz@xbsd.org>
# $FreeBSD$

PORTNAME=	ldapsh
PORTVERSION=	2.00
PORTREVISION=	3
PORTEPOCH=	1
CATEGORIES=	net
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:LOOSIFER

MAINTAINER=	flz@FreeBSD.org
COMMENT=	Interactive shell used to administer ldap directories

BUILD_DEPENDS=	p5-Term-ReadKey>=0:${PORTSDIR}/devel/p5-Term-ReadKey \
		p5-ReadLine-Perl>=0:${PORTSDIR}/devel/p5-ReadLine-Perl \
		p5-perl-ldap>=0:${PORTSDIR}/net/p5-perl-ldap \
		p5-Date-Manip>=0:${PORTSDIR}/devel/p5-Date-Manip \
		p5-ParseLex>=0:${PORTSDIR}/devel/p5-ParseLex
RUN_DEPENDS:=	${BUILD_DEPENDS}

SUB_FILES=	pkg-message

MAN1=		ldapsh.1
MAN3=		Net::LDAP::Shell.3 Net::LDAP::Config.3 \
		Net::LDAP::Shell::Parse.3 Net::LDAP::Shell::Util.3

USES=		perl5
USE_PERL5=	configure

NO_STAGE=	yes
post-patch:
	${REINPLACE_CMD} -e "s,/usr/local/bin/perl,${PERL}," ${WRKSRC}/ldapsh

post-install:
	${MKDIR} ${DOCSDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/COMMANDS ${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/examples/ldapsh_config ${EXAMPLESDIR}/
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
