# New ports collection makefile for:	Cricket
# Date created:		20 November 1999
# Whom:			torstenb
#
# $FreeBSD$
#

PORTNAME=	cricket
PORTVERSION=	0.72
CATEGORIES=	net
MASTER_SITES=	http://www.munitions.com/~jra/cricket/dists/

MAINTAINER=	torstenb@FreeBSD.org

RUN_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VERSION}/${PERL_ARCH}/SNMP_Session.pm:${PORTSDIR}/net/p5-SNMP_Session
RUN_DEPENDS+=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VERSION}/${PERL_ARCH}/RRDs.pm:${PORTSDIR}/net/rrdtool
RUN_DEPENDS+=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VERSION}/${PERL_ARCH}/Digest/MD5.pm:${PORTSDIR}/security/p5-Digest-MD5
RUN_DEPENDS+=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VERSION}/${PERL_ARCH}/LWP.pm:${PORTSDIR}/www/p5-libwww
RUN_DEPENDS+=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VERSION}/${PERL_ARCH}/Time/Zone.pm:${PORTSDIR}/devel/p5-TimeDate
RUN_DEPENDS+=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VERSION}/${PERL_ARCH}/Time/HiRes.pm:${PORTSDIR}/devel/p5-Time-HiRes

NO_PACKAGE=	"needs customization"

USE_PERL5=	yes

FETCH_BEFORE_ARGS=	-b
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
	@${ECHO} "http://www.munitions.com/~jra/cricket/. The documentation can"
	@${ECHO} "be found in ${PREFIX}/cricket/doc/ too."

.include <bsd.port.mk>
