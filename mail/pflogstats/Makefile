# New ports collection makefile for:	pflogstats
# Date created:			30 April 2003
# Whom:				Andrew J. Caines <A.J.Caines@halplant.com>
#
# $FreeBSD$
#

PORTNAME=	pflogstats
PORTVERSION=	20030404
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

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500601
IGNORE=         Port requires perl 5.6.1 or later. Install lang/perl5 then try again
.endif

post-patch:
# fix location of PERL
	@${REINPLACE_CMD} -e 's|/usr/bin/perl|${PERL}|' ${WRKSRC}/*.pl
	@${REINPLACE_CMD} -e 's|/usr/local/lib/pflogstats|${SITE_PERL}/Pflogstats|' ${WRKSRC}/*.pl

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME}.pl  ${PREFIX}/bin/${PORTNAME}
	@${MKDIR} ${PREFIX}/lib/perl5/site_perl/${PERL_VER}/Pflogstats
	${INSTALL_DATA} ${WRKSRC}/pflogstats-*.pm ${SITE_PERL}/Pflogstats
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/pflogstats
.for i in README INSTALL ChangeLog BUGS TODO LICENSE CREDITS
	${INSTALL_DATA} ${WRKSRC}/$i ${PREFIX}/share/doc/pflogstats
.endfor
.endif

.include <bsd.port.post.mk>
