# New ports collection makefile for:   fwanalog
# Date created:                11 March 2002
# Whom:                        Kimura Fuyuki <fuyuki@mj.0038.net>
#
# $FreeBSD$
#

PORTNAME=	fwanalog
PORTVERSION=	0.6.9
CATEGORIES=	security
MASTER_SITES=	http://tud.at/programm/fwanalog/

MAINTAINER=	cy@FreeBSD.org
COMMENT=	A firewall log summarizer that uses Analog

RUN_DEPENDS=	analog:${PORTSDIR}/www/analog

ETCDIR=		${PREFIX}/etc/${PORTNAME}
PLIST_SUB+=	ETCDIR=${ETCDIR}
CONFFILES=	fwanalog-dom.tab \
		fwanalog.analog.conf \
		fwanalog.analog.conf.local \
		fwanalog.lng \
		fwanalog.opts \
		services.conf

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
	${INSTALL_SCRIPT} ${WRKSRC}/fwanalog.sh ${PREFIX}/sbin/fwanalog
	${MKDIR} ${ETCDIR}
.for i in ${CONFFILES}
	${INSTALL_DATA} ${WRKSRC}/${i} ${ETCDIR}/${i}-dist
	${TEST} -f ${ETCDIR}/${i} || ${INSTALL_DATA} ${WRKSRC}/${i} ${ETCDIR}/${i}
.endfor

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
