# New ports collection makefile for:	pflogstats
# Date created:			30 April 2003
# Whom:				Andrew J. Caines <A.J.Caines@halplant.com>
#
# $FreeBSD$
#

PORTNAME=	pflogstats
PORTVERSION=	1.1.1
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.aerasec.de/pub/linux/postfix/pflogsumm/${PORTNAME}/

MAINTAINER=	A.J.Caines@halplant.com
COMMENT=	Postfix Log Statistics Reporter

RUN_DEPENDS=	p5-Date-Calc>=0:${PORTSDIR}/devel/p5-Date-Calc \
		p5-Net-IP>=0:${PORTSDIR}/net-mgmt/p5-Net-IP \
		p5-Proc-ProcessTable>=0:${PORTSDIR}/devel/p5-Proc-ProcessTable \
		p5-Number-Format>=0:${PORTSDIR}/textproc/p5-Number-Format \
		p5-XML-Dumper>=0:${PORTSDIR}/textproc/p5-XML-Dumper

NO_BUILD=	yes
USES=		perl5
SITE_PERL_INST=	${SITE_PERL:S/${LOCALBASE}/${PREFIX}/}

post-patch:
	@${REINPLACE_CMD} \
		-e 's|/usr/bin/perl.*|${PERL}|' \
		-e 's|/usr/local/lib/pflogstats|${SITE_PERL_INST}/Pflogstats|' \
			${WRKSRC}/apachelogiostats.pl \
			${WRKSRC}/pflogstats.pl \
			${WRKSRC}/sqwmstats.pl

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME}.pl  ${PREFIX}/bin/${PORTNAME}
	@${MKDIR} ${SITE_PERL_INST}/Pflogstats
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}-*.pm ${SITE_PERL_INST}/Pflogstats
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in README INSTALL ChangeLog BUGS TODO LICENSE CREDITS
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

post-install:
	@${CAT} ${PKGDIR}/pkg-message

.include <bsd.port.mk>
