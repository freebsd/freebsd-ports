# New ports collection makefile for:	pflogstats
# Date created:			30 April 2003
# Whom:				Andrew J. Caines <A.J.Caines@halplant.com>
#
# $FreeBSD$
#

PORTNAME=	pflogstats
PORTVERSION=	1.0.1
PORTEPOCH=	1
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.aerasec.de/pub/linux/postfix/pflogsumm/${PORTNAME}/

MAINTAINER=	A.J.Caines@halplant.com
COMMENT=	Postfix Log Statistics Reporter

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Date/Calc.pm:${PORTSDIR}/devel/p5-Date-Calc \
		${SITE_PERL}/Net/IP.pm:${PORTSDIR}/net-mgmt/p5-Net-IP \
		${SITE_PERL}/${PERL_ARCH}/Proc/ProcessTable.pm:${PORTSDIR}/devel/p5-Proc-ProcessTable \
		${SITE_PERL}/Number/Format.pm:${PORTSDIR}/textproc/p5-Number-Format \
		${SITE_PERL}/XML/Dumper.pm:${PORTSDIR}/textproc/p5-XML-Dumper

NO_BUILD=	yes
USE_PERL5=	yes
USE_REINPLACE=	yes
SITE_PERL_INST=	${SITE_PERL:S/${LOCALBASE}/${PREFIX}/}

post-patch:
# fix location of PERL
	@${REINPLACE_CMD} -e 's|/usr/local/lib/pflogstats|${SITE_PERL_INST}/Pflogstats|' ${WRKSRC}/*.pl

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME}.pl  ${PREFIX}/bin/${PORTNAME}
	@${MKDIR} ${SITE_PERL_INST}/Pflogstats
	${INSTALL_DATA} ${WRKSRC}/pflogstats-*.pm ${SITE_PERL_INST}/Pflogstats
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in README INSTALL ChangeLog BUGS TODO LICENSE CREDITS
	${INSTALL_DATA} ${WRKSRC}/$i ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
