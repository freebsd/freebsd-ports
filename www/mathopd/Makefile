# Created by: tobez@plab.ku.dk
# $FreeBSD$

PORTNAME=	mathopd
PORTVERSION=	1.5p8
CATEGORIES=	www
MASTER_SITES=	http://www.mathopd.org/dist/

MAINTAINER=	michiel@boland.org
COMMENT=	Small, yet fast HTTP server

CFLAGS+=	-DFREEBSD_SENDFILE
MAKE_ARGS=	CFLAGS="${CFLAGS}"

DOCS=	CHANGES cgi.txt config.txt running.txt sample.cfg syntax.txt

NO_STAGE=	yes
post-install:
	@${INSTALL_DATA} ${WRKSRC}/doc/sample.cfg ${PREFIX}/etc/mathopd.conf.sample
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/mathopd
	@${INSTALL_DATA} ${WRKSRC}/COPYING ${PREFIX}/share/doc/mathopd
	@${INSTALL_DATA} ${WRKSRC}/README  ${PREFIX}/share/doc/mathopd
.for df in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/doc/${df}  ${PREFIX}/share/doc/mathopd
.endfor
.endif
	${INSTALL_SCRIPT} ${FILESDIR}/mathopd.sh ${PREFIX}/etc/rc.d/mathopd.sh-dist
	@${SED} -e 's,/usr/local,${PREFIX},g' ${PKGMESSAGE}

.include <bsd.port.mk>
