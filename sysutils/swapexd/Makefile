# New ports collection makefile for:	swapexd
# Date created:				26 March 2011
# Whom:					Jesse Smith
#
# $FreeBSD$
#

PORTNAME=	swapexd
PORTVERSION=	0.3
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://makeapbi.sourceforge.net/${PORTNAME}/

MAINTAINER=	jessefrgsmith@yahoo.ca
COMMENT=	A tool for growing and shrinking on-disk swap space

WRKSRC=	${WRKDIR}/${PORTNAME}

PLIST_FILES=	sbin/${PORTNAME} etc/rc.d/swapexd

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e "s,%%PREFIX%%,${PREFIX},g" ${WRKSRC}/rc.d/swapexd
	@${REINPLACE_CMD} -e "s,/etc/,${PREFIX}/etc/,g" ${WRKSRC}/swapexd.h
.if ${OSVERSION} < 800076
	@${REINPLACE_CMD} -e "s,swapctl -s -m ,swapctl -s -h ,g" ${WRKSRC}/swapexd.c
.endif
# Clang fix
	@${REINPLACE_CMD} -e '1s/^CC=.*$$/CC=${CC}/' ${WRKSRC}/${MAKEFILE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/sbin/
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.conf ${PREFIX}/etc/${PORTNAME}.conf.sample
	${INSTALL_SCRIPT} ${WRKSRC}/rc.d/swapexd ${PREFIX}/etc/rc.d

# Deal with config files -- would be a shame to have to make a pkg-plist this
# small
post-install:
	${ECHO_CMD} '@unexec cmp -s %D/etc/${PORTNAME}.conf.sample %D/etc/${PORTNAME}.conf && rm -f %D/etc/${PORTNAME}.conf || true 2>/dev/null' >> ${TMPPLIST}
	${ECHO_CMD} 'etc/${PORTNAME}.conf.sample' >> ${TMPPLIST}
	${ECHO_CMD} '@exec [ -f %D/etc/${PORTNAME}.conf ] || cp -p %D/%F %B/${PORTNAME}.conf' >> ${TMPPLIST}
	[ -f %D/etc/${PORTNAME}.conf ] \
		|| ${CP} -p ${PREFIX}/etc/${PORTNAME}.conf.sample \
				${PREFIX}/etc/${PORTNAME}.conf

.include <bsd.port.post.mk>
