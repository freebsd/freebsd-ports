# Created by: Edwin Groothuis (edwin@mavetju.org)
# $FreeBSD$

PORTNAME=	tcl-manual
PORTVERSION=	20130208
CATEGORIES=	lang
MASTER_SITES=	SF/tcl/Tcl/
DISTFILES=	

MAINTAINER=	edwin@mavetju.org
COMMENT=	Documentation for TCL (Tool Command Language)

NO_WRKSUBDIR=	yes
NO_BUILD=	yes

VERSIONS=	8.4.19 \
		8.5.14 \
		8.6.0

.for v in ${VERSIONS}
DISTFILES+=	$v/tcl$v-html.tar.gz
.endfor

NO_STAGE=	yes
post-patch:
.for v in ${VERSIONS}
	@${REINPLACE_CMD} -e 's|<b>tclsh</b>|<b>tclsh${v:R}</b>|g; \
	    s|/usr/local/bin/tclsh|${PREFIX}/bin/tclsh${v:R}|g' \
	    ${WRKSRC}/tcl${v}/html/UserCmd/tclsh.htm
	@${REINPLACE_CMD} -e 's|<b>wish</b>|<b>wish${v:R}</b>|g; \
	    s|/usr/local/bin/wish|${PREFIX}/bin/wish${v:R}|g' \
	    ${WRKSRC}/tcl${v}/html/UserCmd/wish.htm
	@${REINPLACE_CMD} -e 's|tcl\.h|tcl${v:R}/tcl.h|g' \
		${WRKDIR}/tcl${v}/html/TclLib/*
	@${REINPLACE_CMD} -e 's|tk\.h|tk${v:R}/tk.h|g' \
		${WRKDIR}/tcl${v}/html/TkLib/*
	@${FIND} ${WRKSRC} -name "*.bak" -delete
.endfor

do-install:
.for v in ${VERSIONS}
	${MKDIR} ${PREFIX}/share/doc/tcl${v:R:S/.//}
	${CP} -R ${WRKDIR}/tcl${v}/html/* ${PREFIX}/share/doc/tcl${v:R:S/.//}
.endfor

.include <bsd.port.mk>
