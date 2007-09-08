# New ports collection makefile for:	p5-Algorithm-Bucketizer
# Date created:				28 Nov 2006
# Whom:				Christopher Boumenot <boumenot@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	Sysadm-Install
PORTVERSION=	0.23
CATEGORIES=	sysutils perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../by-authors/id/M/MS/MSCHILLI
PKGNAMEPREFIX=	p5-

MAINTAINER=	boumenot@gmail.com
COMMENT=	Typical installation tasks for system administrators

BUILD_DEPENDS=	${SITE_PERL}/Log/Log4perl.pm:${PORTSDIR}/devel/p5-Log-Log4perl \
		${SITE_PERL}/LWP/Simple.pm:${PORTSDIR}/www/p5-libwww \
		${SITE_PERL}/File/Temp.pm:${PORTSDIR}/devel/p5-File-Temp
RUN_DEPENDS=	${BUILD_DEPENDS}

.if defined(WITH_ARCHIVE_TAR)
BUILD_DEPENDS+=	${SITE_PERL}/Archive/Tar.pm:${PORTSDIR}/archivers/p5-Archive-Tar
RUN_DEPENDS+=	${SITE_PERL}/Archive/Tar.pm:${PORTSDIR}/archivers/p5-Archive-Tar
.endif

.if defined(WITH_EXPECT)
BUILD_DEPENDS+=	${SITE_PERL}/Expect.pm:${PORTSDIR}/lang/p5-Expect
RUN_DEPENDS+=	${SITE_PERL}/Expect.pm:${PORTSDIR}/lang/p5-Expect
.endif

PERL_CONFIGURE=	yes

MAN3=		Sysadm::Install.3

.include <bsd.port.mk>
