# You'll need graphics/libglut in order to build example program

CC=%%CC%%
RM=%%RM%%

CFLAGS=		%%CFLAGS%% -DHAVE_ZLIB -O3 -I%%X11BASE%%/include
LDFLAGS=	-lgl2ps -lGL -lGLU -lglut -L%%X11BASE%%/lib -lX11 -lXi -lXmu -lm -lz

gl2psTest: gl2psTest.o
	${CC} ${LDFLAGS} $> -o $@

.c.o:
	${CC} -c ${CFLAGS} $*.c

clean:
	${RM} -f gl2psTest gl2psTest.o
