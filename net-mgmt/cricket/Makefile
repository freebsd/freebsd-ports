# New ports collection makefile for:	Cricket
# Date created:		20 November 1999
# Whom:			torstenb
#
# $FreeBSD$
#

PORTNAME=	cricket
PORTVERSION=	1.0.2
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	torstenb@FreeBSD.org

RUN_DEPENDS=	${SITE_PERL}/SNMP_Session.pm:${PORTSDIR}/net/p5-SNMP_Session \
		${SITE_PERL_ARCH}/RRDs.pm:${PORTSDIR}/net/rrdtool \
		${SITE_PERL_ARCH}/Digest/MD5.pm:${PORTSDIR}/security/p5-Digest-MD5 \
		${SITE_PERL}/LWP.pm:${PORTSDIR}/www/p5-libwww \
		${SITE_PERL}/Time/Zone.pm:${PORTSDIR}/devel/p5-TimeDate \
		${SITE_PERL_ARCH}/Time/HiRes.pm:${PORTSDIR}/devel/p5-Time-HiRes

SITE_PERL=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}
SITE_PERL_ARCH=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}

NO_PACKAGE=	"needs customization"
USE_PERL5=	yes
SCRIPTS_ENV+=	PERL5=${PERL5}

do-build:

do-install:
	@${MKDIR} -m 755 ${PREFIX}/cricket
	@${CP} -R ${WRKSRC}/* ${PREFIX}/cricket
	@find ${PREFIX}/cricket -name \*.orig -or -name \*.bak | xargs ${RM} -f

post-install:
	@${ECHO} ""
	@${ECHO} "Cricket has been installed in ${PREFIX}/cricket. You'll find"
	@${ECHO} "executables and configfiles there. Please take a look at"
	@${ECHO} "http://cricket.sourceforge.net/. The documentation can"
	@${ECHO} "be found in ${PREFIX}/cricket/doc/ too."

.include <bsd.port.mk>
