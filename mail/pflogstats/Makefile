# New ports collection makefile for:	pflogstats
# Date created:			30 April 2003
# Whom:				Andrew J. Caines <A.J.Caines@halplant.com>
#
# $FreeBSD$
#

PORTNAME=	pflogstats
PORTVERSION=	20030721
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.aerasec.de/pub/linux/postfix/pflogsumm/pflogstats/

MAINTAINER=	A.J.Caines@halplant.com
COMMENT=	Postfix Log Statistics Reporter

RUN_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/Date/Calc.pm:${PORTSDIR}/devel/p5-Date-Calc \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Net/IP.pm:${PORTSDIR}/net/p5-Net-IP \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/Proc/ProcessTable.pm:${PORTSDIR}/devel/p5-Proc-ProcessTable \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Number/Format.pm:${PORTSDIR}/textproc/p5-Number-Format

NO_BUILD=	yes
USE_PERL5=	yes
USE_REINPLACE=	yes

post-patch:
# fix location of PERL
	@${REINPLACE_CMD} -e 's|/usr/local/lib/pflogstats|${SITE_PERL}/Pflogstats|' ${WRKSRC}/*.pl

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME}.pl  ${PREFIX}/bin/${PORTNAME}
	@${MKDIR} ${PREFIX}/lib/perl5/site_perl/${PERL_VER}/Pflogstats
	${INSTALL_DATA} ${WRKSRC}/pflogstats-*.pm ${PREFIX}/lib/perl5/site_perl/${PERL_VER}/Pflogstats
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in README INSTALL ChangeLog BUGS TODO LICENSE CREDITS
	${INSTALL_DATA} ${WRKSRC}/$i ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
