# Created by: Kimura Fuyuki <fuyuki@mj.0038.net>
# $FreeBSD$

PORTNAME=	fwanalog
PORTVERSION=	0.6.9
PORTREVISION=	6
CATEGORIES=	security
MASTER_SITES=	http://tud.at/programm/fwanalog/

MAINTAINER=	cy@FreeBSD.org
COMMENT=	Firewall log summarizer that uses Analog

RUN_DEPENDS=	analog:www/analog

CONFFILES=	fwanalog-dom.tab \
		fwanalog.analog.conf \
		fwanalog.analog.conf.local \
		fwanalog.lng \
		fwanalog.opts \
		services.conf

OPTIONS_DEFINE=	DOCS

post-patch:
	${REINPLACE_CMD} \
		-e "s,the script's directory.*$$,${ETCDIR},;" \
		-e 's,cd .*$$,cd ${ETCDIR},; s,sh\$$/,\$$/.,' \
		${WRKSRC}/fwanalog.sh
	${REINPLACE_CMD} -e 's/"freebsd/"ipf/; s/"ipflog/"messages/' \
		${WRKSRC}/fwanalog.opts.freebsd

do-build:
	${LN} ${WRKSRC}/fwanalog.opts.freebsd ${WRKSRC}/fwanalog.opts

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/fwanalog.sh ${STAGEDIR}${PREFIX}/sbin/fwanalog
	@${MKDIR} ${STAGEDIR}${ETCDIR}
.for i in ${CONFFILES}
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${ETCDIR}/${i}.sample
.endfor

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
