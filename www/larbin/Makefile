# Created by: Hiten Pandya <hiten@uk.FreeBSD.org>
# $FreeBSD$

PORTNAME=	larbin
PORTVERSION=	2.6.3
PORTREVISION=	2
CATEGORIES=	www
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Powerful HTTP crawler with an easy interface

BUILD_DEPENDS=	bash:${PORTSDIR}/shells/bash \
		makedepend:${PORTSDIR}/devel/makedepend

OPTIONS_DEFINE=	DOCS

USES=		shebangfix gmake
SHEBANG_FILES=	configure
GNU_CONFIGURE=	yes
MAKE_JOBS_UNSAFE=	yes

PORTDOCS=	*
PLIST_FILES=	bin/larbin etc/larbin.conf.sample

NO_STAGE=	yes
.include <bsd.port.options.mk>

pre-everything::
	@${ECHO_MSG} "====================================================================="
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Make sure you have a look at the larbin documentation available at:"
	@${ECHO_MSG} "  http://larbin.sourceforge.net/custom-eng.html."
	@${ECHO_MSG} ""
	@${ECHO_MSG} "====================================================================="

post-patch:
	@${REINPLACE_CMD} -e \
		'/CC=/s|echo|${TRUE:T}| ; \
		 /CXX=/s|echo|${TRUE:T}| ; \
		 /-lpthread/d' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		's|CFLAGS:=-O3|CFLAGS+=| ; \
		 s|CXXFLAGS:=|CXXFLAGS+=| ; \
		 s|-O3|| ; \
		 s|-I-||' ${WRKSRC}/src/larbin.make
	@${REINPLACE_CMD} -e \
		'/delete \[\] tab/s|^|//|' ${WRKSRC}/src/utils/histogram.cc

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/larbin ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/larbin.conf ${PREFIX}/etc/larbin.conf.sample
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/* ${DOCSDIR}
.endif

post-install:
	@${ECHO_MSG} "====================================================================="
	@${ECHO_MSG} ""
	@${ECHO_MSG} "You must invoke larbin with the name of the configuration file, e.g:"
	@${ECHO_MSG} "larbin -c config-file"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Documentation: ${DOCSDIR}"
	@${ECHO_MSG} "Sample Configuration file: ${PREFIX}/etc/larbin.conf.sample"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "====================================================================="

.include <bsd.port.mk>
