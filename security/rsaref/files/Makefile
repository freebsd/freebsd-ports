# $FreeBSD$

O= o
SO= so
LIB= ar

.SUFFIXES: .c .so .o

.c.so:
	${CC} -fpic -DPIC ${CFLAGS} -c ${.IMPSRC} -o ${.TARGET}

RSAREFLIB=librsaref.a
SORSAREFLIB=librsaref.so.2

all: ${RSAREFLIB} ${SORSAREFLIB}

$(RSAREFLIB) : desc.$(O) digit.$(O) md2c.$(O) md5c.$(O) nn.$(O) prime.$(O)\
  rsa.$(O) r_encode.$(O) r_dh.$(O) r_enhanc.$(O) r_keygen.$(O) r_random.$(O)\
  r_stdlib.$(O)
	$(LIB) rc $@ $>
	ranlib $@

$(SORSAREFLIB) : desc.$(SO) digit.$(SO) md2c.$(SO) md5c.$(SO) nn.$(SO) prime.$(SO)\
  rsa.$(SO) r_encode.$(SO) r_dh.$(SO) r_enhanc.$(SO) r_keygen.$(SO) r_random.$(SO)\
  r_stdlib.$(SO)
.if ${PORTOBJFORMAT} == elf
	${CC} -o $@ -shared -Wl,-soname,$@ $>
.else
	ld -Bshareable -x -o $@ $>
.endif
