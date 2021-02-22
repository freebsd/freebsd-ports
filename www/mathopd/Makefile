# Created by: tobez@plab.ku.dk
# $FreeBSD$

PORTNAME=	mathopd
PORTVERSION=	1.5p8
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://www.mathopd.org/dist/

MAINTAINER=	michiel@boland.org
COMMENT=	Small, yet fast HTTP server

LICENSE=	BSD3CLAUSE

CFLAGS+=	-DFREEBSD_SENDFILE

OPTIONS_DEFINE=	DOCS

DOCS=	CHANGES cgi.txt config.txt running.txt sample.cfg syntax.txt

do-install:
	${INSTALL} -s ${WRKSRC}/src/mathopd ${STAGEDIR}${PREFIX}/sbin/
	${INSTALL_DATA} ${WRKSRC}/doc/sample.cfg ${STAGEDIR}${PREFIX}/etc/mathopd.conf.sample
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/doc/mathopd
	${INSTALL_DATA} ${WRKSRC}/COPYING ${STAGEDIR}${PREFIX}/share/doc/mathopd
	${INSTALL_DATA} ${WRKSRC}/README  ${STAGEDIR}${PREFIX}/share/doc/mathopd
.for df in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/doc/${df}  ${STAGEDIR}${PREFIX}/share/doc/mathopd
.endfor
	${INSTALL_SCRIPT} ${FILESDIR}/mathopd.sh ${STAGEDIR}${PREFIX}/etc/rc.d/mathopd.sh-dist
	@${SED} -e 's,/usr/local,${PREFIX},g' ${PKGMESSAGE}

.include <bsd.port.mk>
