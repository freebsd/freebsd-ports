# $FreeBSD$

DESTDIR=
BINDIR=	${PREFIX}/bin

CFLAGS+=	-I${LOCALBASE}/include/ijs
LDADD=	-L${LOCALBASE}/lib -lijs

PROG=	ijs_server_epsonepl
SRCS=	ijs_server_epsonepl.c epl_compress.c epl_job_footer.c epl_job_header.c \
	epl_page_footer.c epl_page_header.c epl_print_stripe.c

SCRIPTS=	ps2epl
MAN=

.include <bsd.prog.mk>
