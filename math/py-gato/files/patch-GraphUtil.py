--- GraphUtil.py.orig	Wed May 16 13:16:58 2001
+++ GraphUtil.py	Mon Sep  3 12:21:49 2001
@@ -223,13 +223,13 @@
 	    break
 
 	if lineNr == 2: # Read directed and euclidian
-	    splitLine = split(line[:-1],';')	    
-	    G.directed = eval(split(splitLine[0],':')[1])
-	    G.simple = eval(split(splitLine[1],':')[1])
-	    G.euclidian = eval(split(splitLine[2],':')[1])
-	    intWeights = eval(split(splitLine[3],':')[1])
-	    nrOfEdgeWeights = eval(split(splitLine[4],':')[1])
-	    nrOfVertexWeights = eval(split(splitLine[5],':')[1])
+	    splitLine = split(';',line[:-1])	    
+	    G.directed = eval(split(':',splitLine[0])[1])
+	    G.simple = eval(split(':',splitLine[1])[1])
+	    G.euclidian = eval(split(':',splitLine[2])[1])
+	    intWeights = eval(split(':',splitLine[3])[1])
+	    nrOfEdgeWeights = eval(split(':',splitLine[4])[1])
+	    nrOfVertexWeights = eval(split(':',splitLine[5])[1])
 	    for i in xrange(nrOfEdgeWeights):
 		G.edgeWeights[i] = EdgeWeight(G)
 	    for i in xrange(nrOfVertexWeights):
@@ -237,33 +237,33 @@
 
 
 	if lineNr == 5: # Read nr of vertices
-	    nrOfVertices = eval(split(line[:-2],':')[1]) # Strip of "\n" and ; 
+	    nrOfVertices = eval(split(':',line[:-2])[1]) # Strip of "\n" and ; 
 	    firstVertexLineNr = lineNr + 1
 	    lastVertexLineNr  = lineNr + nrOfVertices
 	
 	if  firstVertexLineNr <= lineNr and lineNr <= lastVertexLineNr: 
-	    splitLine = split(line[:-1],';')
+	    splitLine = split(';',line[:-1])
 	    v = G.AddVertex()
-	    x = eval(split(splitLine[1],':')[1])
-	    y = eval(split(splitLine[2],':')[1])
+	    x = eval(split(':',splitLine[1])[1])
+	    y = eval(split(':',splitLine[2])[1])
 	    for i in xrange(nrOfVertexWeights):
-		w = eval(split(splitLine[3+i],':')[1])
+		w = eval(split(':',splitLine[3+i])[1])
 		G.vertexWeights[i][v] = w
 
 	    E[v] = Point2D(x,y)
 	    
 	if lineNr == lastVertexLineNr + 1: # Read Nr of edges
-	    nrOfEdges = eval(split(line[:-2],':')[1]) # Strip of "\n" and ; 
+	    nrOfEdges = eval(split(':',line[:-2])[1]) # Strip of "\n" and ; 
 	    firstEdgeLineNr = lineNr + 1
        	    lastEdgeLineNr  = lineNr + nrOfEdges
 
 	if firstEdgeLineNr <= lineNr and lineNr <= lastEdgeLineNr: 
-	    splitLine = split(line[:-1],';')
-	    h = eval(split(splitLine[0],':')[1])
-	    t = eval(split(splitLine[1],':')[1])
+	    splitLine = split(';',line[:-1])
+	    h = eval(split(':',splitLine[0])[1])
+	    t = eval(split(':',splitLine[1])[1])
 	    G.AddEdge(t,h)
 	    for i in xrange(nrOfEdgeWeights):
-		G.edgeWeights[i][(t,h)] = eval(split(splitLine[3+i],':')[1])
+		G.edgeWeights[i][(t,h)] = eval(split(':',splitLine[3+i])[1])
  
 	lineNr = lineNr + 1
 
@@ -345,7 +345,7 @@
 	if not line:
 	    return retval
 
-	token = filter(lambda x: x != '', split(line[:-1],"[\t ]*"))
+	token = filter(lambda x: x != '', split("[\t ]*",line[:-1]))
 
 	if len(token) == 1 and token[0] == ']':
 	    return retval
